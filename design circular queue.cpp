//Design Circular Queue
class MyCircularQueue {
public:
    int q[2000];
    int f=-1,r=-1;
    int size=0;
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;
        if(f==-1){
            f=r=0;
        }
        else
        {   r=(r+1)%size;}
            q[r]=value;
        return true;

    }
    
    bool deQueue() {
        if(isEmpty())
        return false;
        if(f==r)
        f=r=-1;
        else
        f=(f+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return q[f];
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        return q[r];
    }
    
    bool isEmpty() {
      if(f==-1)  
      return true;
      return false;
    }
    
    bool isFull() {
        if((r+1)%size==f)
        return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 *
 */