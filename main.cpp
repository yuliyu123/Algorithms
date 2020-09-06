#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <unistd.h>

using namespace std;

static int instanceId = 0;

struct Data
{
    int val = 0;
};

class StateHelper
{
public:
    StateHelper()
    {
        cout << "i'm stateHelper constructor" << endl;
    }

    int addInstanceId()
    {
        cout << "++instanceId: " << ++instanceId << endl;
        data = new Data();
        cout << "data->val: " << data->val << endl;
        return instanceId;
    }

    ~StateHelper()
    {
        cout << "i'm stateHelper deconstructor" << endl;
    }

    Data *data;
};

typedef std::shared_ptr<StateHelper> StateHelperPtr;

class InternalBase
{
public:
    InternalBase()
    {
        cout << "InternalBase construct" << endl;
        stateHelperPtr_ = std::make_shared<StateHelper>();
        cout << "stateHelperPtr_.use_count(): " << stateHelperPtr_.use_count()
            << " and &stateHelperPtr_:" << &stateHelperPtr_
            << " and &(*stateHelperPtr_)" << &(*stateHelperPtr_) << endl;
        std::thread::id tid = std::this_thread::get_id();
        cout << __func__  << " std::this_thread::get_id(): " << tid << endl;
    }

    virtual void useStateHelper()
    {
        cout << "i'm InternalBase useStateHelper()" << endl;
    }

    ~InternalBase()
    {
        cout << "InternalBase decontructor" << endl;
    }

public:
    StateHelperPtr stateHelperPtr_;
};


// std::queue<InternalBase> InternalBaseQueue;
std::queue<std::shared_ptr<InternalBase> > InternalBaseQueue;

class GrantTransmiter : public InternalBase
{
public:
    GrantTransmiter()
    {
        cout << "GrantTransmiter" << endl;
    }

    virtual void useStateHelper();
};

void GrantTransmiter::useStateHelper()
{
    int count = 1000;
    while (count)
    {
        // usleep(10000);
        std::thread::id tid = std::this_thread::get_id();
        cout << "main std::this_thread::get_id(): " <<  tid << endl;
        stateHelperPtr_->addInstanceId();
        --count;
    }
}

class HbTransmiter : public InternalBase
{
public:
    HbTransmiter()
    {
        cout << "HbTransmiter" << endl;
    }

    virtual void useStateHelper() override;
};

void HbTransmiter::useStateHelper()
{
    stateHelperPtr_->addInstanceId();
}

void pushToQueue(std::shared_ptr<InternalBase> grantPtr)
{
    for (int i = 0; i < 100; ++i) {
        InternalBaseQueue.push(grantPtr);
    }
}

void modifyStateHelper()
{
    std::shared_ptr<InternalBase> hbPtr;

    for (int i = 0; i < 1000; ++i) {
        // usleep(20000);
        hbPtr = std::make_shared<HbTransmiter>();;
        InternalBaseQueue.push(hbPtr);
    }
};

int main(void)
{
    std::shared_ptr<InternalBase> grantPtr = std::make_shared<GrantTransmiter>();
    // InternalBase* grantPtr = new GrantTransmiter();
//    pushToQueue(grantPtr);
//    grantPtr->useStateHelper();
//    cout << "InternalBaseQueue size: " << InternalBaseQueue.size() << endl;

    std::thread th2(&modifyStateHelper);
    th2.detach();
    grantPtr->useStateHelper();
}

