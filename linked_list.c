#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int num; //節點中儲存的data，此處以一個int變數為例
    struct Node* next; //此指標指向下一個節點(是一個結構變數，指標型態必須與被指向的對象搭配，就跟指向int變數的指標之型態為int*的道理一樣)
};
typedef struct Node node; //使用typedef將struct Node型態重新定義成名為node之型態(下面程式碼寫起來比較方便)
node* append(node* head,node* new_node_ptr);
node* lookup(node* head,int target_num);
node* delete(node* head,int delete_num);
node* insert(node* head,node* insert_node_ptr,int insert_num);
void print_linked_list(node* head);



int main()
{
    node* head=NULL;  //宣告鏈結串列的開頭節點指標，該指標會指向串列開頭節點，也就是該指標會儲存串列開頭節點的記憶體位址，若目前串列內沒有節點，則該開頭節點指標指向NULL
    printf("Linked list head pointer(memory address) is %d\n",head);
    int command_num;
    while(1)
    {
        printf("\nPlease provide a number, and the following are the corresponding instructions for the given number.\n");
        printf("0:quit\n");
        printf("1:append\n");
        printf("2:lookup\n");
        printf("3:delete\n");
        printf("4:insert\n");
        printf("5:print\n\n");
        scanf("%d",&command_num);
        if(command_num==0)
        {
            break;
        }else if(command_num==1)
        {
            int number;
            printf("Please provide a number you would like to store in the new node.\n");
            scanf("%d",&number);
            node* new_node_ptr;
            new_node_ptr=(node*)malloc(sizeof(node));
            new_node_ptr->num=number;
            new_node_ptr->next=NULL;
            head=append(head,new_node_ptr);
        }else if(command_num==2)
        {
            int target_num;
            printf("Please provide a number you would like to search for in the list.\n");
            scanf("%d",&target_num);
            node* target_node_ptr=lookup(head,target_num);
            if(target_node_ptr==NULL)
            {
                printf("The number does not exist in the list.\n");
            }else
            {
                printf("The number exists in a node within the list, and the address of that node is %d\n",target_node_ptr);
            }
        }else if(command_num==3)
        {
            int delete_num;
            printf("Please enter the node number you want to delete. Note: 0 represents the head node.\n");
            scanf("%d",&delete_num);
            head=delete(head,delete_num);
        }else if(command_num==4)
        {
            int number;
            printf("Please provide a number you would like to store in the new node.\n");
            scanf("%d",&number);
            node* insert_node_ptr;
            insert_node_ptr=(node*)malloc(sizeof(node));
            insert_node_ptr->num=number;
            insert_node_ptr->next=NULL;
            int insert_num;
            printf("Please provide the position number where you want to insert. Note: 0 represents the position before the head node.\n");
            scanf("%d",&insert_num);
            head=insert(head,insert_node_ptr,insert_num);
        }else if(command_num==5)
        {
            print_linked_list(head);
        }

    }

    

    return 0;

}

node* append(node* head,node* new_node_ptr)
{
    if(head==NULL)  //目前串列為空
    {
        head=new_node_ptr;
        return head;
    }else
    {
        node* backup=NULL;
        node* current=head;
        while(current!=NULL)
        {
            backup=current;
            current=current->next;
        }
        backup->next=new_node_ptr;
        return head;
    }
}

node* lookup(node* head,int target_num)
{
    if(head==NULL)
    {
        return head;
    }else
    {
        node* backup=NULL;
        node* current=head;
        while(current!=NULL)
        {
            if(current->num==target_num)
            {
                return current;
            }else
            {
                backup=current;
                current=current->next;
            }
            
        }
        return current;
    }
}

node* delete(node* head,int delete_num)
{
    int count=0;
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
        return head;
    }
    else
    {
        if(delete_num==0)
        {
            node* tmp_ptr=head;
            head=head->next;
            tmp_ptr->next=NULL;
            free(tmp_ptr);
            return head;
        }else
        {
            node* backup=NULL;
            node* current=head;
            while(current!=NULL)
            {
                if(count==delete_num)
                {
                    node* tmp_ptr=current;
                    backup->next=current->next;
                    tmp_ptr->next=NULL;
                    free(tmp_ptr);
                    return head;
                }else
                {
                    backup=current;
                    current=current->next;
                    count++;
                }
                
            }
            printf("delete_num error!\n");
            return head;
        }
    }
}

node* insert(node* head,node* insert_node_ptr,int insert_num)
{
    int count=0;
    if(head==NULL)
    {
        if(insert_num==0)
        {
            head=insert_node_ptr;
            return head;
        }else
        {
            printf("insert_num error!\n");
            return head;
        }
        
    }else
    {
        if(insert_num==0)
        {
            insert_node_ptr->next=head;
            head=insert_node_ptr;
            return head;
        }else
        {
            node* backup=NULL;
            node* current=head;
            while(current!=NULL)
            {
                if(count==insert_num)
                {
                    backup->next=insert_node_ptr;
                    insert_node_ptr->next=current;
                    return head;
                }else
                {
                    backup=current;
                    current=current->next;
                    count++;
                }
                
            }
            printf("insert_num error!\n");
            return head;
        }
    }
}

void print_linked_list(node* head)
{
    printf("\n\n");
    if(head==NULL)
    {
        printf("linked list is empty!\n");
    }else
    {
        node* backup=NULL;
        node* current=head;
        while(current!=NULL)
        {
            printf("Current node's memory address is %d\n",current);
            printf("Current node's num is %d\n",current->num);
            backup=current;
            current=current->next;
        }
    }
    printf("\n\n");
}













