void ReversePrint(Node *head){
	string ans = "";
	int temp;
	while (head != NULL){
		temp = head -> data;
		ans.insert(0, to_string(temp)+"\n");
		head = head -> next;

	}
	cout << ans;

}