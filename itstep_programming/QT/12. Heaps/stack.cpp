#include <iostream>
#include <Windows.h>
template <typename T>
class Stack
{
   struct Element
   {
      T num;
      Element * p;
   };
   Element * head;
   HANDLE myHeap;
public:
   Stack(){ head = NULL; 
	   myHeap = HeapCreate(HEAP_NO_SERIALIZE,100,0);}
   T pop();
   void push(T);
   ~Stack() {
	   if(HeapDestroy(myHeap)) 
	   std::cout << "Good!" << std::endl; }
};
template <typename T>
void Stack<T>::push(T a)
{
   if (head == NULL)
   {
      head = reinterpret_cast<Element*>(
 HeapAlloc(myHeap, HEAP_NO_SERIALIZE,sizeof(Element)));
      head->num = a;
      head->p = NULL;
   }
   else
   {  Element * tmp = head;
      head = reinterpret_cast<Element*>(
 HeapAlloc(myHeap, HEAP_NO_SERIALIZE, sizeof(Element)));
      head->num = a;
      head->p = tmp;
   }
}
template <typename T>
T Stack<T>::pop()
{
   if (head != NULL)
   {
      Element tmp = *head;
      HeapFree(myHeap,HEAP_NO_SERIALIZE,head);         //delete head;
      head = tmp.p;
      return tmp.num;
   }
   else throw 5;
}

int main()
{
   Stack<int> obj;
   obj.push(1),  obj.push(2),  obj.push(3);
   /*try{
   cout << obj.pop() << endl;
   cout << obj.pop() << endl;
   cout << obj.pop() << endl;
   }
   catch (int) {cout << "Use ploho" << endl;}
   */
   return 0;
}
