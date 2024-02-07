#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;

void print_sll(Node *head)
{
    Node *temt = head;

    while (temt != NULL)
    {
        printf("%d -> ", temt->data);
        temt = temt->next;
    }

    printf("NULL");
}
void print_dll(node *head)
{
    node *temt = head;

    while (temt != NULL)
    {
        printf("%d <-> ", temt->data);
        temt = temt->next;
    }

    printf("NULL \n");
}

void addLast_dll(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    head->prev = NULL;

    newNode->data = data;
    node *temt = head;

    if (temt->next == NULL)
    {
        temt->next = newNode;
        newNode->prev = head;
        newNode->next = NULL;
        return;
    }

    else
    {
        while (temt->next != NULL)
        {
            temt = temt->next;
        }
        temt->next = newNode;
        newNode->prev = temt;
    }
}

node *creater_dll()
{
    printf("Enter the DLL size : ");
    int n;
    scanf("%d", &n);
    node *newNode = (node *)malloc(sizeof(node));
    printf("i=1 | data=");
    int data;
    scanf("%d", &data);
    newNode->data = data;

    for (int i = 1; i < n; i++)
    {
        printf("i=%d | data=", i);
        int data;
        scanf("%d", &data);
        addLast_dll(newNode, data);
    }

    return newNode;
}

void print_cll(Node *head)
{
    Node *temt = head;
    printf("%d -> ", temt->data);
    temt = temt->next;
    // printf("hello");
    while (temt != head)
    {
        printf("%d -> ", temt->data);
        temt = temt->next;
    }

    printf("NULL\n");
}

void addLast_sll(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temt = head;
    newNode->data = data;
    while (temt->next != NULL)
    {
        temt = temt->next;
    }

    temt->next = newNode;
}
void addLast_cll(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temt = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL)
    {
        head->next = newNode;
        newNode->next = head;
        return;
    }
    while (temt->next != head)
    {
        temt = temt->next;
    }

    temt->next = newNode;
    newNode->next = head;
    return;
}

Node *creater_sll()
{
    printf("Enter the sll size : ");
    int n;
    scanf("%d", &n);
    Node *newNode = (Node *)malloc(sizeof(Node));

    for (int i = 0; i < n; i++)
    {
        printf("i=%d | data=", i);
        int data;
        scanf("%d", &data);
        addLast_sll(newNode, data);
    }

    return newNode->next;
}
Node *creater_cll()
{
    printf("Enter the cll size : ");
    int n;
    scanf("%d", &n);
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("i=%d | data=", 0);
    int data;
    scanf("%d", &data);
    newNode->data = data;
    for (int i = 1; i < n; i++)
    {
        printf("i=%d | data=", i);
        int data;
        scanf("%d", &data);
        addLast_cll(newNode, data);
        // printf("hello");
    }

    return newNode;
}

Node *max_ind_cll(Node *head)
{
    Node *temt = head;
    Node *max = head;

    temt = temt->next;

    while (temt != head)
    {
        if (temt->data > max->data)
        {
            max = temt;
        }
        temt = temt->next;
    }
    return max;
}

void q_no2(Node *h1, Node *h2)
{

    Node *temt = h1;

    while (temt->next != NULL)
    {
        temt = temt->next;
    }

    temt->next = h2;

    print_sll(h1);
}

Node *reverse(Node *h1)
{
    Node *curr = h1;
    Node *prev = NULL;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void multiple(int k, Node *head)
{
    int i = 0;

    Node *temt = head;

    while (temt != NULL)
    {
        if (i % k == 0)
        {
            printf("%d -> ", temt->data);
        }
        temt = temt->next;
        i++;
    }
    printf("NULL \n");
}
void multiple_modified(int k, Node *head)
{
    int i = 0;
    int c = 0;
    Node *temt = head;
    Node *t = head->next;
    int size = 1;
    while (t != head)
    {
        t = t->next;
        size++;
    }

    while (1 == 1)
    {
        if (i % k == 0 && temt->data != 69)
        {
            printf("%d -> ", temt->data);
            temt->data = -69;
            c++;
        }
        temt = temt->next;
        if (c == size)
        {
            break;
        }
        i++;
    }
    printf("NULL \n");
}

void remove_node_ad(Node *add, Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != add)
    {
        next = curr->next;
        prev = curr;
        curr = next;
        next = next->next;
    }
    prev->next = next;
}

struct Node *reversee(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (current != NULL)
        head->next = reversee(current, k);

    return prev;
}

void insert_sll(Node *head, int n, int data)
{
    int i = 0;
    Node *curr = head;
    Node *prev = NULL;

    while (i < n)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    prev->next = newNode;
    newNode->next = curr;
}

int isPalindrom(Node *h1)
{
    Node *slow = h1;
    Node *fast = h1;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *midNode = slow;
    Node *curr = midNode;
    Node *prev = NULL;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Node *start2 = prev;
    Node *start1 = h1;

    while (start1 != NULL && start2 != NULL)
    {
        if (start1->data != start2->data)
        {
            return 0;
        }
        start1 = start1->next;
        start2 = start2->next;
    }
    return 1;
}
struct Node *kAltReverse(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next;
    struct Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (head != NULL)
        head->next = current;

    count = 0;
    while (count < k - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current != NULL)
        current->next = kAltReverse(current->next, k);

    return prev;
}
void add_middle_dll(node *head, int n, int data)
{
    int i = 0;
    node *temt = head;

    while (i < n - 1)
    {
        i++;
        temt = temt->next;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    node *temt2 = temt->next;

    temt->next = newNode;
    newNode->prev = temt;
    newNode->next = temt2;
    temt2->prev = newNode;
}
void add_middle_cll(Node *head, int n, int data)
{
    int i = 0;
    Node *temt = head;

    while (i < n - 2)
    {

        temt = temt->next;
        i++;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temt2 = temt->next;

    temt->next = newNode;

    newNode->next = temt2;
}
void delete_cll(Node *head, int n)
{
    int i = 0;
    Node *temt = head;

    while (i < n - 2)
    {

        temt = temt->next;
        i++;
    }
    temt->next = temt->next->next;
}

void copier(node *head, int *array)
{
    node *temt = head;
    int i = 0;

    while (temt != NULL)
    {

        array[i] = temt->data;
        i++;
        temt = temt->next;
    }
}

int main()
{
    int q_no ;
    printf("Question Number : ");
    scanf("%d",&q_no);
    printf("\n\n");
    if (q_no == 1)
    {
        Node *h1 = creater_cll();
        Node *maxh1 = max_ind_cll(h1);
        print_cll(h1);
        Node *h2 = creater_cll();
        Node *maxh2 = max_ind_cll(h2);
        print_cll(h2);
        printf("Max element of ll1 :%d and ll2 is :%d \n", maxh1->data, maxh2->data);
        Node *temt_1st_linker = maxh1->next;
        maxh1->next = maxh2;
        Node *temt2;
        temt2 = h2;
        while (temt2->next != maxh2)
        {
            temt2 = temt2->next;
        }
        temt2->next = temt_1st_linker;
        print_cll(h1);
    }

    if (q_no == 2)
    {
        Node *h1 = creater_sll();
        Node *h2 = creater_sll();

        q_no2(h1, h2);
    }

    if (q_no == 3)
    {
        Node *h1 = creater_sll();
        Node *rev_id = reverse(h1);
        print_sll(rev_id);
    }

    if (q_no == 4)
    {
        Node *h1 = creater_sll();
        int k;
        printf("k = ");
        scanf("%d", &k);
        multiple(k, h1);
    }

    if (q_no == 5)
    {
        Node *h1 = creater_cll();
        int k;
        printf("K = ");
        scanf("%d", &k);
        multiple_modified(k, h1);
    }

    if (q_no == 6)
    {
        int marks[500] = {0};
        Node *head = creater_sll();

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            if (marks[curr->data] == 0)
            {
                marks[curr->data] = 1;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;

                curr = curr->next;
            }
        }

        print_sll(head);
    }

    if (q_no == 7)
    {
        int k;
        printf("K = ");
        scanf("%d", &k);
        Node *h1 = creater_sll();
        Node *rh1 = reversee(h1, k);
        print_sll(rh1);
    }

    if (q_no == 9)
    {
        Node *h1 = creater_sll();
        Node *temt = h1->next;

        while (temt != NULL)
        {
            remove_node_ad(temt, h1);
            if (temt->next != NULL)
            {
                temt = temt->next->next;
            }
            else
            {
                temt = NULL;
            }
        }
        print_sll(h1);
    }

    if (q_no == 10)
    {
        Node *h1 = creater_sll();

        Node *curr = h1->next;
        Node *prev = h1;

        while (curr != NULL)
        {
            int tt = curr->data;
            curr->data = prev->data;
            prev->data = tt;
            if (curr->next != NULL && curr->next->next != NULL)
            {
                prev = curr->next;
                curr = curr->next->next;
            }
            else
            {
                curr = NULL;
            }
        }
        print_sll(h1);
    }

    if (q_no == 11)
    {
        // The worst-case time complexity to insert a number in a fixed-size array is O(n), where n is the size of the array.
        Node *h1 = creater_sll();
        printf("Enter the index to be inserted :");
        int ind;
        scanf("%d", &ind);
        printf("Enter the data");
        int data;
        scanf("%d", &data);

        print_sll(h1);
        insert_sll(h1, ind, data);
        print_sll(h1);
    }

    if (q_no == 12)
    {
        Node *h1 = creater_sll();

        Node *slow = h1;
        Node *fast = h1;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("%d", slow->data);
    }

    if (q_no == 13)
    {
        Node *h1 = creater_sll();

        if (isPalindrom(h1))
        {
            printf("LL is palindrom ");
        }
        else
        {
            printf("LL is not palindrom");
        }
    }

    if (q_no == 14)
    {
        int marks[500] = {0};
        Node *h1 = creater_sll();
        Node *temt = h1;

        while (temt != NULL)
        {
            marks[temt->data]++;
            temt = temt->next;
        }
        temt = h1;
        while (temt != NULL)
        {
            if (marks[temt->data] != 0)
            {
                printf("Freq(%d) =%d \n", temt->data, marks[temt->data]);
                marks[temt->data] = 0;
            }
            temt = temt->next;
        }
    }

    if (q_no == 15)
    {
        Node *h1 = creater_sll();
        Node *h2 = creater_sll();

        Node *curr1 = h1;
        Node *curr2 = h2;

        while (curr1->next != NULL)
        {
            Node *temt = curr1->next;
            curr1->next = curr2;
            curr1 = temt;
            temt = curr2->next;
            curr2->next = curr1;

            curr2 = temt;
        }

        print_sll(h1);
    }

    if (q_no == 16)
    {
        int sum;
        printf("Sum : ");
        scanf("%d", &sum);
        Node *h1 = creater_sll();
        Node *i = h1;
        Node *j;

        while (i != NULL)
        {

            j = i->next;

            while (j != NULL)
            {
                if ((j->data + i->data) == sum)
                {
                    printf("(%d,%d) , ", i->data, j->data);
                }
                j = j->next;
            }

            i = i->next;
        }
    }

    if (q_no == 17)
    {
        printf("K = ");
        int k;
        scanf("%d", &k);

        Node *h1 = creater_sll();

        Node *id = kAltReverse(h1, k);

        print_sll(id);
    }
    if (q_no == 18)
    {
        node *h1 = creater_dll();
        print_dll(h1);
        printf("\n");
        printf("Input the position to insert a new node :");
        int n;
        scanf("%d", &n);
        printf("Enter the data for position %d : ", n);
        int data;
        scanf("%d", &data);
        add_middle_dll(h1, n, data);

        print_dll(h1);
    }

    if (q_no == 19)
    {
        node *h1 = creater_dll();

        node *temt = h1;
        while (temt->next->next != NULL)
        {
            temt = temt->next;
        }
        temt->next = NULL;
        print_dll(h1);
    }

    if (q_no == 20)
    {
        node *h1 = creater_dll();

        node *temt = h1;
        int max = temt->data;
        temt = temt->next;
        while (temt != NULL)
        {
            if (temt->data > max)
            {
                max = temt->data;
            }
            temt = temt->next;
        }
        printf("Maximum :%d", max);
    }

    if (q_no == 21)
    {
        Node *h1 = creater_cll();
        printf("Input the position to insert a new node :");
        int n;
        scanf("%d", &n);
        printf("Enter the data for position %d : ", n);
        int data;
        scanf("%d", &data);
        add_middle_cll(h1, n, data);
        print_cll(h1);
    }
    if (q_no == 22)
    {
        Node *h1 = creater_cll();
        printf("Input the position to delete a  node :");
        int n;
        scanf("%d", &n);
        delete_cll(h1, n);
        print_cll(h1);
    }
    if (q_no == 23)
    {
        Node *h1 = creater_cll();
        printf("Input the data to find :");
        int n;
        scanf("%d", &n);
        Node *temt = h1;
        int i = 1;
        if (temt->data == n)
        {
            printf("Found at Node No : %d", i + 1);
            i = 96;
        }
        temt = temt->next;
        while (temt != h1)
        {
            if (temt->data == n)
            {
                printf("Found at Node No : %d", i + 1);
                i = 96;
                break;
            }
            i++;
            temt = temt->next;
        }
        if (i != 96)
        {
            printf("Data not found");
        }
    }

    if (q_no == 24)
    {
        Node *h1 = creater_sll();

        Node *t1 = h1;
        Node *t2 = h1;

        while (t1 != NULL)
        {
            while (t2->next != NULL)
            {
                if (t2->data > t2->next->data)
                {
                    int temt = t2->data;
                    t2->data = t2->next->data;
                    t2->next->data = temt;
                }
                t2 = t2->next;
            }
            t1 = t1->next;
            t2 = h1;
        }
        print_sll(h1);
    }

    if (q_no == 25)
    {
        node *h1 = creater_dll();
        char chr[1000] = "->  ";

        node *temt = h1;
        char str[20];

        while (temt != NULL)
        {
            sprintf(str, "%d ", temt->data);
            strcat(chr, str);
            temt = temt->next;
        }

        printf("%s", chr);
    }

    if (q_no == 26)
    {
        int size = 0;

        node *h1 = creater_dll();
        node *temt = h1;
        while (temt != NULL)
        {
            temt = temt->next;
            size++;
        }
        int *array = malloc(size * sizeof(*array));

        copier(h1, array);

        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
    }
}