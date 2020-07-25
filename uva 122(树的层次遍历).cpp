#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Node{
public:
    int value;
    Node* left;
    Node* right;
};

Node* queue[256];
void show(Node* root){
    memset(queue,0,sizeof(queue));
    int qbegin=0;
    int qend=0;
    int qlen = sizeof(queue)/sizeof(Node*); 
    stringstream out;

    queue[qend] = root;
    qend = (qend+1) % qlen; 

    while(qbegin!=qend){
        Node* nownode = queue[qbegin];
        // cout<<nownode->value<<endl;
        if(nownode!=root) out<<" ";

        if(nownode->value){
            out<<nownode->value;
        }else{
            out.str("not complete");
            // cout<<"not complete";
            break;
        }

        qbegin  = (qbegin+1) % qlen;
        if(nownode->left){
            queue[qend] = nownode->left;
            qend = (qend+1) % qlen; 
        }
            
        if(nownode->right){
            queue[qend] = nownode->right;
            qend = (qend+1) % qlen; 
        }
    }
    cout<<out.str()<<endl;
}

int main()
{
    string nodestr;
    int newtree = 1;
    Node* root;
    int badtree = 0;
    while (cin>>nodestr){
        if(newtree == 1){
            /* 新的树 */
            newtree = 0;
            root = new Node();
            // nownode = root;
            badtree = 0;
        }

        int comma = nodestr.find(',');
        if(comma == nodestr.npos){
            /* 树木结束了,该输出结果了  */

            if(badtree){
                cout<<"not complete"<<endl;
            }else{
                show(root);
            }
            newtree = 1;
        }else{
            Node* nownode = root;
            if(!badtree){
                int size = nodestr.size();
                int n = atoi(nodestr.substr(1,comma-1).c_str());
                for(int i=comma+1;i<size-1;i++){
                    Node** nextstep;
                    if(nodestr[i] == 'L'){
                        nextstep = &(nownode->left);
                    }else if(nodestr[i] == 'R'){
                        nextstep = &(nownode->right);
                    }

                    if(!(*nextstep)){
                        *nextstep = new Node();
                    }
                    nownode = *nextstep;
                }
                // cout<<nodestr<<" "<<comma<<" "<<size<<" "<<" "<<" ";
                // cout<<nownode<<" nownode->value  "<<nownode->value<<"   n "<<n<<endl;
                if(nownode->value){
                    badtree = 1;
                }else{
                    nownode->value = n;
                }
            }
        }
        
    }



    return 0;
}
// AC at 2020/3/17