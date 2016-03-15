Node* InsertNth(Node *head, int data, int position){
	Node *node, *temp;
	node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	if (position == 0){
		node -> next = head;
		return node;
	}else{
		temp = head;
		while (position-- > 1) temp = temp->next;

		if (temp -> next == NULL){
			node -> next = NULL;
			temp -> next = node;
		}else{
			node -> next = temp -> next;
			temp -> next = node;
		}
		return head;
	}

}