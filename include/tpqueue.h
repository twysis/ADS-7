// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM* next, * previous;
  };
  ITEM* start, * end;
  TPQueue::ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = item->previous = nullptr;
    return item;
}
 public:
  TPQueue() : start(nullptr), end(nullptr) {}
  T pop();
  void push(const T& value);
};

template<typename T>
T TPQueue<T>:: pop() {
  if (start && end) {
    ITEM* temp = start->next;
    if (temp) {
      temp->previous = nullptr;
    }
    T value = start->value;
    delete start;
    start = temp;
    if (!start) {
      end = nullptr;
    }
  return value;
  } else {
    throw std::string("Queue empty");
  }
}

template<typename T>
void TPQueue<T>:: push(const T& value) {
  ITEM* temp = start;
  ITEM* item = create(value);
  while (temp && temp->value.prior >= value.prior)
    temp = temp->next;
    if (!temp && start) {
      end->next = item;
      item->previous = end;
      end = item;
    } else if (!temp && !start) {
      start = end = item;
    } else if (!temp->previous) {
      start->previous = item;
      item->next = start;
      start = item;
    } else {
      temp->previous->next = item;
      item->previous = temp->previous;
      item->next = temp;
      temp->previous = item;
    }
}


struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
