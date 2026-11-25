class MyCircularQueue {
public:
//哎呀，就当普通队列做吗，不过下一个就是(i+1)%N， 然后看空不空和满是count
//他说不能用queue
    int count = 0;
    vector<int> data;
    int front = 0, rear = 0;
    int capacity;
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
    }
    //这里定义的rear是队尾的下一个元素
    bool enQueue(int value) {
        if(!isFull()){
        data[rear] = value;
        rear = (rear+1)%capacity;
        count++;
        return true;
        }else{
            return false;
        }
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front = (front+1)%capacity;
            count--;
            return true;
        }else{
            return false;
        }
    }
    
    int Front() {
        if(!isEmpty()){
            return data[front];
        }else{
            return -1;
        }
    }
    
    int Rear() {
        if(!isEmpty()){
            return data[(rear+capacity-1)%capacity];
        }else{
            return -1;
        }
    }
    //return front == rear看不出是空还是满
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==capacity;
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
 */