/* Function to print nodes of extreme corners
of each level in alternate order */

// http://www.practice.geeksforgeeks.org/problem-page.php?pid=700308

void printExtremeNodes(Node* root){
    if(root==NULL)return ;
    if(root->left==NULL && root->right==NULL){
        cout << root->data << endl;
        return;
    }
    queue<map<Node*, int> >qe;
    bool flag=true;
    map<Node*,int>mp;
    mp.insert(make_pair(root,1));
    qe.push(mp);
    int prev=root->data;
    int rootDta=prev;
    while(!qe.empty()){
        map<Node*,int>ii;
        ii=qe.front();
        
        if(flag && ii.begin()->second%2==0 && ii.begin()->first->data!=rootDta){
            cout << prev << " " << ii.begin()->first->data << " " ;
            flag=false;
        }
        
        if(!flag && ii.begin()->second%2!=0 && prev!=rootDta) flag=true;
        
        if(ii.begin()->first->left){
            map<Node*,int>mp;
            mp.insert(make_pair(ii.begin()->first->left,1+(ii.begin()->second)));
            qe.push(mp);
        }
        
        if(ii.begin()->first->right){
            map<Node*,int>mp;
            mp.insert(make_pair(ii.begin()->first->right,1+(ii.begin()->second)));
            qe.push(mp);
        }
        
        prev=ii.begin()->first->data;
        qe.pop();
    }
    if(flag)cout << prev ;
}
