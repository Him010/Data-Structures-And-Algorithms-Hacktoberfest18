#include<bits/stdc++.h>
using namespace std;
 struct node
{
	int data ;
	node * left;
	node * right;
};
 node * createNode(int data)
{
 node * temp = new node();
 temp->data = data;
temp->right= NULL;
temp->left = NULL;
 return temp;
}
 node * add(node * head , int data)
{
	if(head == NULL)
	{
		head = createNode(data);
		return head;
	}
	
	else if(data <= head->data)
	{
		head->left = add(head->left , data);
	}
	
	else if ( data > head->data )
	{
		head -> right = add(head->right , data);
	}
	
	return head;
}
 int max(node * head)
{
	if(head->right == NULL)
	{
	 return head->data;
	}
	
	else
	{
		head=head->right;
		return max(head);
	}
}
 int min(node * head)
{
	if(head->left == NULL)
	{
	  return head->data;
	}
	
	else
	{
		head = head->left;
		return min(head);
	}
	
}
 int main()
{
	node * head = NULL;
	int n,a; char ch='y';
	while(ch=='y'){
	start:
  cout << "What operation you want to perform on tree:\n" <<"1. Insert\n 2. To find max element\n3. To find min element \n4.Exit";
	cout<<"\n Enter your choice: "<<a;
  switch(a){
    case 1 : cout<<"Enter the element:";
             cin>>n;
             head=add(head,n);
             
    case 2 : cout<<max(head);
    case 3 : cout<<min(head);
    case 4 : exit(0);
    default : cout<<"Wrong choice";
              getch();
              goto start;
  }
  return 0;
  }
