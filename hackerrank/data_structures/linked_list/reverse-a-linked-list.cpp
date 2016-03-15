Node* Reverse(Node *head){
	Node *temp, *temp2, *prev;
	temp = head;
	if (temp == NULL || temp -> next == NULL){
		return temp;
	}else if(temp->next->next == NULL){
		temp = temp->next;
		temp -> next = head;
		head -> next = NULL;
		return temp;
	}else{
		prev = temp;
		temp = temp -> next;
		while (temp != NULL){
			temp2 = temp -> next;
			temp -> next = prev;
			prev = temp;
			if (temp2 != NULL){
				temp = temp2;
			}else{
				break;
			}
		}
		head -> next = NULL;
		return temp;
	}
}