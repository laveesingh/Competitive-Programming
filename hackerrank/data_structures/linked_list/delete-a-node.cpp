Node* Delete(Node *head, int position){
	if (position == 0) return head->next;
	Node *temp = head, *temp2;
	while (position-- > 1){
		temp = temp -> next;
	}
	temp2 = temp -> next;
	temp->next = temp2->next;
	free(temp2);
	return head;
}