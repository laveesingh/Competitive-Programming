int GetNode(Node *head, int position){
	int len = 0;
	Node *temp = head;
	while (temp != NULL){
		temp = temp -> next;
		len += 1;
	}
	int pos = len-position-1;
	temp = head;
	while (pos--){
		temp = temp -> next;
	}
	return temp -> data;
}