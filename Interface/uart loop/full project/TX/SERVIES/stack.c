
#include "stack.h"
//////////////////////////////////functions body///////////////////////////////////
void createEmptyStack(ST_stack_t *stack)
{
    sp=-1;
}
///////////////////////////////////////////////////////////////////////////////////
s8 push(ST_stack_t *stack, u8 data)
{
    stack_status status;
    if ( sp == STACK_SIZE-1)
    {
        //status =-1;
        status=STACK_FULL;
    }
    else
    {
        sp++;
        stack->elements[sp]=data;
        //status =0;
        status=STACK_OK;
    }
    return status ;
}
///////////////////////////////////////////////////////////////////////////////////
s8 pop(ST_stack_t *stack, u8 *data)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;
    }

    else
    {
        *data =stack->elements[sp];
        sp--;
        // status =0;
        status=STACK_OK;
    }



    return status;
}
///////////////////////////////////////////////////////////////////////////////////
s8 printStack(ST_stack_t *stack)
{
    s8 sp_holder=sp;
    stack_status  status;
    if (sp_holder==-1)
    {
        //status =-2;
        status=STACK_EMPTY;

    }
    else if ( sp_holder == STACK_SIZE-1)
    {
        //status =-1;
        status=STACK_FULL;
    }
    else
    {
        status=STACK_OK;
        // status =0;

    }
    if (status==STACK_OK||status==STACK_FULL)
    {
        while(sp_holder>-1)
        {
            printf("%d->| %d\n",sp_holder,(stack->elements[sp_holder]));
            sp_holder--;

        }
    }

    return status;
}
///////////////////////////////////////////////////////////////////////////////////
s8 getStackTop(ST_stack_t *stack, u8 *topData)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;

    }

    else
    {
        *topData =stack->elements[sp];
        // printf("Peek value: %d\n", stack->elements[stack->top]);
        // status =0;
        status=STACK_OK;
    }



    return status;
}
///////////////////////////////////////////////////////////////////////////////////
s8 isEmpty(ST_stack_t *stack)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;
    }
    return status;
}
///////////////////////////////////////////////////////////////////////////////////
s8 isFull(ST_stack_t *stack)
{
    stack_status status;

    if (sp==STACK_SIZE-1)
    {
        // status=-2;
        status=STACK_FULL;
    }
    return status;

}
///////////////////////////////////////////////////////////////////////////////////
