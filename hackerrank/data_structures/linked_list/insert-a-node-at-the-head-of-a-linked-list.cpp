Node* Insert(Node *head, int data){
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}