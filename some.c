#include <stdio.h>
#include <stdlib.h>

struct Cell
{
    int in;
    struct Cell *n;
};

struct DoubleCell
{
    int in;
    struct DoubleCell *n;
    struct DoubleCell *b;
};

void printOut(struct Cell *p1)
{
    struct Cell *p = p1;
    while (p)
    {
        printf("%d  ", p->in);
        p = p->n;
    }
    printf("\n");
}

void append(struct Cell **p1, int controlled, int attribute)
{
    int number;
    if(controlled){
        number = attribute;
        goto control;
    }
    printf("Enter the value to append\n");
    scanf(" %d", &number);
    control: if (*p1)
    {
        struct Cell *p = *p1;
        while (p->n)
        {
            p = p->n;
        }
        p->n = (struct Cell *)malloc(sizeof(struct Cell));
        p = p->n;
        p->in = number;
        p->n = NULL;
    }
    else
    {
        struct Cell *p = (struct Cell *)malloc(sizeof(struct Cell));
        *p1 = p;
        (*p1)->in = number;
        (*p1)->n = NULL;
    }
};

void prepend(struct Cell **p1)
{
    printf("Enter the value to prepend\n");
    int number;
    scanf(" %d", &number);
    struct Cell *p = (struct Cell *)malloc(sizeof(struct Cell));
    if (*p1)
    {
        p->n = *p1;
        p->in = number;
        *p1 = p;
    }
    else
    {
        *p1 = p;
        (*p1)->in = number;
        (*p1)->n = NULL;
    }
};

void reverse(struct Cell **p1)
{
    if ((*p1)->n)
    {
        struct Cell *current = *p1, *next, *prev = NULL;
        while (current)
        {
            next = current->n;
            current->n = prev;
            prev = current;
            current = next;
        }
        *p1 = prev;
    }
    else
    {
        printf("Empty or consists of 1 element\n");
    }
};

void add(struct Cell **p1)
{
    int index, number, k = 1, size = 0;
    struct Cell *p = *p1, *add = (struct Cell *)malloc(sizeof(struct Cell));
    if (*p1)
    {
        while (p)
        {
            p = p->n;
            size++;
        }
        printf("Choose an index in range 1-%d\n", size + 1);
        scanf(" %d", &index);
        if (index == 1)
            prepend(p1);
        else if (index == size + 1)
            append(p1, 0, 0);
        else if (index > 1 && index <= size)
        {
            printf("Enter the number\n");
            scanf(" %d", &number);
            add->in = number;
            p = *p1;
            while (k < index - 1)
            {
                p = p->n;
                k++;
            }
            add->n = p->n;
            p->n = add;
        }
        else
        {
            printf("No\n");
        }
    }
    else
    {
        printf("Use append or prepend\n");
    }
};

void removeCell(struct Cell **p1, int controlled)
{
    int size = 0, index, k = 1;
    if(controlled){
        struct Cell *deleted;
        goto control;
    }
    if ((*p1)->n)
    {
        struct Cell *deleted, *p = *p1;
        while (p)
        {
            p = p->n;
            size++;
        }
        printf("Choose an index in range 1-%d\n", size);
        scanf(" %d", &index);
        p = *p1;
        if (index == 1)
        {
            control: deleted = *p1;
            *p1 = deleted->n;
        }
        else if (index > 1 && index <= size)
        {
            while (k < index - 1)
            {
                p = p->n;
                k++;
            }
            deleted = p->n;
            p->n = deleted->n;
        }
        else
            printf("No\n");
        free(deleted);
        deleted = NULL;
    }
    else if (*p1)
    {
        free(*p1);
        *p1 = NULL;
    }
    else
    {
        printf("Nothing to delete\n");
    }
};

void sort(struct Cell **p1)
{
    int swapped = 1;
    struct Cell *p, *start = *p1, *temp = NULL, *aux, *step;
    if (!*p1)
    {
        printf("Nothing to sort\n");
    }
    else if (!(*p1)->n)
    {
        printf("Nothing to sort\n");
    }
    else if (!(*p1)->n->n)
    {
        if ((*p1)->in > (*p1)->n->in)
        {
            (*p1)->n->n = *p1;
            *p1 = (*p1)->n;
            (*p1)->n->n = NULL;
        }
    }
    else
    {
        while (swapped)
        {
            swapped = 0;
            step = start;
            while (step->n->n != temp && !(temp && temp->n == step))
            {
                if (step == start && step->in > step->n->in)
                {
                    p = step;
                    start = p->n;
                    p->n = start->n;
                    start->n = p;
                    swapped = 2;
                }
                else if (step->n->in > step->n->n->in)
                {
                    p = step;
                    aux = p->n->n;
                    p->n->n = aux->n;
                    aux->n = p->n;
                    p->n = aux;
                    swapped = 1;
                }
                step = swapped == 2 ? start : step->n;
            }
            temp = step;
        }
        *p1 = start;
    }
}

void search(struct Cell *p1)
{
    int number, index = 0;
    printf("Enter the number to be searched\n");
    scanf(" %d", &number);
    while (p1)
    {
        index++;
        if (p1->in == number)
            printf("Found at index %d\n", index);
        p1 = p1->n;
    }
};

void switchPointer(struct Cell **p1, struct Cell *firstList, struct Cell *secondList)
{

    *p1 = firstList == *p1 ? secondList : firstList;
    printf("List switched\n");
}

void join(struct Cell *p1, struct Cell *first, struct Cell *second)
{
    struct Cell *current = p1, *listToBeAdded;
    while (current->n)
        current = current->n;
    listToBeAdded = p1 == first ? second : first;
    while (listToBeAdded)
    {
        current->n = (struct Cell *)malloc(sizeof(struct Cell));
        current = current->n;
        current->in = listToBeAdded->in;
        current->n = NULL;
        listToBeAdded = listToBeAdded->n;
    }
    printf("Selected list was expended with unselected, unselected list wasn't changed\n");
};

void backwards(struct Cell *p1)
{
    struct DoubleCell *start = (struct DoubleCell *)malloc(sizeof(struct DoubleCell));
    start->b = NULL;
    start->n = NULL;
    while (p1->n)
    {
        start->n = (struct DoubleCell *)malloc(sizeof(struct DoubleCell));
        start->in = p1->in;
        start->n->b = start;
        start = start->n;
        p1 = p1->n;
    }
    start->in = p1->in;
    start->n = NULL;
    while (start)
    {
        printf("%d  ", start->in);
        start = start->b;
    }
    printf("\n");
};

void readFile(struct Cell **p1)
{
    int buffer;
    while(*p1){
        removeCell(p1, 1);
    }     
    FILE *filePointer = fopen("linkedList.txt", "r");
    if (!filePointer)
    {
        printf("Use Write to create a file\n");
    }
    else
    {
        while (fscanf(filePointer, " %d", &buffer) == 1)
        {
            append(p1, 1, buffer);
        }
    }

    fclose(filePointer);
}

void writeFile(struct Cell *p1)
{
    FILE *filePointer = fopen("linkedList.txt", "w+");
    while (p1)
    {
        fprintf(filePointer, "%d ", p1->in);
        p1 = p1->n;
    }
    fclose(filePointer);
}

void main()
{
    int select = 1, selected = 1;
    struct Cell *firstList = NULL, *secondList = NULL, *pointer = firstList;
    while (select)
    {
        if (selected - 1)
            secondList = pointer;
        else
            firstList = pointer;
        printf("-----------------------------------------------------------------------\n\
(p) Print\n(s) Switch\n(1) Append\n(2) Prepend\n(3) Reverse\n(4) Index add\n(5) Index remove\n\
(6) Sort\n(7) Search\n(8) Join\n(9) Backwards\n(0) Exit\n(r) Read\n(w) Write\n\
----------------------------------------------------------------------\n");
        scanf(" %c", &select);

        switch (select)
        {
        case 'p':
            printOut(pointer);
            break;
        case 's':
            switchPointer(&pointer, firstList, secondList);
            selected = selected - 1 ? 1 : 2;
            break;
        case '1':
            append(&pointer, 0, 0);
            break;
        case '2':
            prepend(&pointer);
            break;
        case '3':
            reverse(&pointer);
            break;
        case '4':
            add(&pointer);
            break;
        case '5':
            removeCell(&pointer, 0);
            break;
        case '6':
            sort(&pointer);
            break;
        case '7':
            search(pointer);
            break;
        case '8':
            join(pointer, firstList, secondList);
            break;
        case '9':
            backwards(pointer);
            break;
        case 'r':
            readFile(&pointer);
            break;
        case 'w':
            writeFile(pointer);
            break;
        case '0':
            select = 0;
            break;
        default:
            break;
        }
    }
    printf("End of the program\n");
}