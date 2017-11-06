#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Stack
{
    int* data;
    size_t capacity = 0;
    size_t size = 0;
};

void StackPush (Stack* stk, int value)
{
    assert (stk);
    assert (stk->size < stk->capacity);

    stk->data [stk->size] = value;

    stk->size ++;

}

int StackPop (Stack* stk)
{
    assert (stk);
    assert (stk->size > 0);

    stk->size --;
    stk->data [stk->size] = 0;


    assert (stk->size >= 0);
}

void StackClean (Stack* stk)
{
    assert (stk);

    for (int i = stk->capacity - 1; i > stk->size; i--)
        stk->data[i] = 0;

    while (stk->size > 0)
    {
        stk->data[stk->size] = 0;
        stk->size --;
    }
    stk->data[stk->size] = 0;

    assert (stk->size == 0);
}

int StackTop (Stack* stk)
{
    assert (stk);
    assert (stk->size > 0);


    return (stk->data [stk->size-1]);
}

int StackSize (Stack* stk)
{
    assert (stk);

    return stk->size;
}

int StackEmpty (Stack* stk)
{
    assert (stk);

    if (stk->size == 0)
        return 1;
    else
        return 0;
}

int StackIsFull (Stack* stk)
{
    assert (stk);

    if ((stk->size) == stk->capacity)
        return 1;
    else
        return 0;
}

int StackOK (Stack* stk)
{
    if (stk == NULL)
    {
        printf ("Stack pointer = NULL\n");
        return 0;
    }

    if (stk->size > stk->capacity)
    {
        printf ("Stack overflow\n");
        return 0;
    }
    return 1;
}

void StackDump (Stack* stk)
{
    assert (stk);

    printf ("Stack capacity = %d\n", stk->capacity);
    printf ("Stack size = %d\n", stk->size);

    for (int i = 0; i < stk->capacity; i++)
        printf ("%10d", i);

    printf ("\n");

    for (int i = 0; i < stk->capacity; i++)
        printf ("%10d", stk->data[i]);
    printf ("\n");
}

void StackCreate (Stack* stk, int capacity)
{
    assert (stk);

    stk->capacity = capacity;

    stk->data  = (int*) calloc (capacity, sizeof (int));

    stk->size = 0;
}

void StackDestroy (Stack* stk)
{
    free (stk->data);
    stk->data = NULL;
    stk->capacity = 0;
    stk->size = 0;
}

int main ()
{
    Stack stk;
    StackCreate(&stk, 6);
    StackPush (&stk, 1);
    StackPush (&stk, 9);
    StackPush (&stk, -15);
    StackPush (&stk, 65);
    StackPush (&stk, 156);

    StackDump(&stk);

    StackDestroy (&stk);

    StackDump (&stk);


}
