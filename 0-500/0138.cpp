class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){return nullptr;}          //特殊情况
        unordered_map<Node*,Node*> map;
        Node* p = head;                             //使用p来遍历原来的链表
        while(p!=nullptr){
            Node * newNode = new Node(p->val);      //循环的过程中创建新的节点，并建立和原来链表中节点的一一对应关系
            map[p]=newNode;                         // key:value 原链表node:新创建node
            p=p->next;             //之前有人问 Node * newNode 是不是重复创建变量了，其实不用担心，在while中，这就相当于string temp ='xxx'一样，本质上是在循环中不断修改一个临时变量
        }

        p=head;                     //p重新回到head，准备将刚刚创建的node连接

        while(p!=nullptr){
            if(p->next){            
                map[p]->next=map[p->next];  //根据原链表的关系，建立新链表的关系
            }
            if(p->random){
                map[p]->random=map[p->random];
            }
            p=p->next;
        }
        return map[head];               //返回新链表
    }
};
