class MyCircularDeque {
 public:
  MyCircularDeque(int k) : k(k), q(k), rear(k - 1) {}
  bool insertFront(int value) {
    if (isFull())
      return false;

    front = (--front + k) % k;
    q[front] = value;
    ++size;
    return true;
  }
  bool insertLast(int value) {
    if (isFull())
      return false;

    rear = ++rear % k;
    q[rear] = value;
    ++size;
    return true;
  }
  bool deleteFront() {
    if (isEmpty())
      return false;

    front = ++front % k;
    --size;
    return true;
  }
  bool deleteLast() {
    if (isEmpty())
      return false;

    rear = (--rear + k) % k;
    --size;
    return true;
  }
  int getFront() {
    return isEmpty() ? -1 : q[front];
  }
  int getRear() {
    return isEmpty() ? -1 : q[rear];
  }
  bool isEmpty() {
    return size == 0;
  }
  bool isFull() {
    return size == k;
  }
 private:
  const int k;
  vector<int> q;
  int size = 0;
  int front = 0;
  int rear;
};