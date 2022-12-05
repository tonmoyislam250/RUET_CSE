#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;
};
int main()
{
  node *head = NULL, *tail = NULL;
  int n, x;
  cout << "How many nodes you need?" << endl;
  cin >> n;
  cout << "ENTer your node values: " << endl;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL)
      head = tmp;
    if (tail == NULL)
      tail = tmp;
    else
    {
      tail->next = tmp;
      tail = tmp;
    }
    // cout << i << "| " << head << "| " << tail << "| " << tmp << "| " << tmp->data << "| " << tail->data << endl;
  }
  // cout << endl
  //      << "i|"
  //      << "head           | "
  //      << "tail          | "
  //      << "p             | "
  //      << "p->data   | "
  //      << "q->data   | " << endl
  //      << endl;
  node *temp = head;
  if (head == NULL)
  {
    cout << "List empty" << endl;
  }
  // cout << "h";
  int i = 1;
  cout << "no node        data next" << endl;
  while (temp != NULL)
  {
    // cout << " --> " << temp->data << " ";
    cout << i << " " << temp << " " << temp->data << " " << temp->next << endl;
    temp = temp->next;
    i++;
  }
  cout << endl;
}

default:
break;
}