class MyQueue {
public:
    int f=0,r=0;
    int q[200];
    MyQueue() {
    }
    
    void push(int x) {
        if(r==200)
        return;
        else
       { q[r]=x;
        r+=1;}
    }
    
    int pop() {
        int y=0;
        if(empty())
        return -1;
        else
        {y=q[f];
        f+=1;}
        return y;
    }
    
    int peek() {
        return q[f];
    }
    
    bool empty() {
        if(f==r)
        return true;
        else
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */