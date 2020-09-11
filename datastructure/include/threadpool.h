#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_



#include<thread>
#include<vector>
#include<queue>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<assert.h>

using namespace std;

//基本任务类
class BasicTask{
public:
    int tasklevel=2;
    virtual void run(){};
    virtual ~BasicTask(){};
};

class ThreadPool{
public:
    //开辟的线程数
    static const int kInitThreadSize=6;

    ThreadPool();
    ~ThreadPool();

private:
    ThreadPool(const ThreadPool&);//静止复制拷贝
    const ThreadPool& operator=(const ThreadPool&);

    //任务队列,按照优先度
    struct taskprioritycmp{
        bool operator()(const BasicTask* a,const BasicTask* b){
            return a->tasklevel >b->tasklevel;
        }
    };
    priority_queue<BasicTask*,vector<BasicTask*>,taskprioritycmp> m_tasks;

    //线程池
    vector<thread*> m_threads;

    //互斥量
    mutex m_mutex;
    mutex m_taskemptymutex;

    //条件变量m_isEmptyCond;
    condition_variable m_cond;
    

    //线程是否开启
    bool m_isStarted;
    
    //任务线程函数
    void threadLoop();

    //从任务队列里选出一个任务
    BasicTask* take();

    //正在执行任务的核数量
    int coreruningNum=0;

public:
    void start();
    void stop();
    void addTask(BasicTask* p);
    void taskwaitEmpty();//等待任务全部完成
    condition_variable m_isEmptyCond;

};

//------------------func
ThreadPool::ThreadPool(){
    m_isStarted=false;
}
ThreadPool::~ThreadPool(){
    if(m_isStarted){
        stop();
    }
}
//开始
void ThreadPool::start(){
    assert(m_threads.empty());
    m_isStarted=true;
    m_threads.reserve(kInitThreadSize);
    for(int i=0;i<kInitThreadSize;i++){
        m_threads.push_back(new thread(bind(&ThreadPool::threadLoop,this)));
    }
}
void ThreadPool::stop(){
    {
        
        unique_lock<mutex> lock(m_mutex);
        m_isStarted=false;
        m_cond.notify_all();
        
    }
    for(vector<thread*>::iterator it=m_threads.begin();it!=m_threads.end();++it){
        (*it)->join();
        delete *it;
        
    }
    m_threads.clear();
}

//线程循环
void ThreadPool::threadLoop(){
    while(m_isStarted){
        //取出任务
        BasicTask* taskp=take();
        
        if(taskp){
            //执行该任务
            taskp->run();
            unique_lock<mutex> loker(m_taskemptymutex);
            coreruningNum--;
        }
        //任务执行完毕，释放内存
        delete taskp;
        //查看任务是否全部完成
        unique_lock<mutex> loker(m_taskemptymutex);
        if(m_tasks.empty()&&coreruningNum==0){
            cout<<"out"<<endl;
            m_isEmptyCond.notify_all();
        }

    }
}

//添加任务
void ThreadPool::addTask(BasicTask* p)
{
  unique_lock<mutex> lock(m_mutex);
  unique_lock<mutex> elocker(m_taskemptymutex);
  /*while(m_tasks.isFull())
    {//when m_tasks have maxsize
      cond2.wait();
    }
  */
  
  m_tasks.push(p);
  m_cond.notify_one();
}

BasicTask* ThreadPool::take(){
    unique_lock<mutex> lock(m_mutex);
    unique_lock<mutex> elocker(m_taskemptymutex);
    //always use a while-loop, due to spurious wakeup
    while(m_tasks.empty() && m_isStarted){
        elocker.unlock();
        m_cond.wait(lock);
        elocker.lock();
    }
    //唤醒后
    BasicTask* tp=nullptr;//一定要初始化，不然会返回野指针
    int size=m_tasks.size();
    if(!m_tasks.empty()&&m_isStarted){
        tp=m_tasks.top();
        m_tasks.pop();
        coreruningNum++;//增加线程工作数
        assert(size-1==m_tasks.size());
        
    }
    return tp;
}

//注意只有当任务数为0，且没有线程在工作的情况下，才算结束
void ThreadPool::taskwaitEmpty(){
    unique_lock<mutex> locker(m_taskemptymutex);
    while(!m_tasks.empty()||coreruningNum!=0){
        m_isEmptyCond.wait(locker);
    }
    
}




#endif 