typedef struct t_rcost
{
    int ra;
    int rb;
    int rra;
    int rrb;
    int rr;
    int rrr;
    int total;
} t_rcost;

typedef struct s_stack
{
    int cnt;
    int start;
    int cap;
    int array[20];
} s_stack;

typedef struct s_pair
{
    int up;
    int down;
} s_pair;

//Not tested - Binary Search with wrap around
int ft_binary_search(int num, const s_stack *stack)
{
    int start;
    int end;
    int pivot;
    int p_pivot;

    start = stack -> start;
    end = stack -> cnt;
    pivot = ((end - start)/2 + start);//logical mid
    p_pivot = pivot % stack -> cap;
    while (pivot != start)
    {
        if (num > stack -> array[p_pivot])
            start = pivot;
        else if (num < stack -> array[p_pivot])
            end = pivot;
        pivot = ((end - start)/2 + start);//logical mid
        p_pivot = pivot % stack -> cap;
    }
    pivot++;//pivot always return 1 down because of int division rounding down
    return(pivot);//logical index
}

//logical index - call this pair function for every number in a stack
s_pair ft_rotation_cost(int num, const s_stack *stack)
{
    s_pair cost;
    int up;
    int down;
    int dest;

    up = 0;
    down = 0;
    cost = (s_pair){0};
    dest = ft_binary_search(num, stack);
    cost.up = dest;
    cost.down = stack -> cnt - dest;
    return (cost);
}
//Returns a struct containing lowest rotation instruction combination
t_rcost ft_final_cost(s_pair *a, s_pair *b)
{
    t_rcost cost_zero;
    t_rcost cost_opp;
    t_rcost cost_same_dir;

    cost_zero = check_zero(a,b);
    cost_opp = check_opp_cost(a,b);
    cost_same_dir = check_same_dir_cost(a,b);
    if (cost_zero.total <= cost_opp.total && cost_zero.total <= cost_same_dir.total)
        return (cost_zero);
    else if (cost_same_dir.total <= cost_zero.total && cost_same_dir.total <= cost_opp.total)
        return (cost_same_dir);
    else
        return (cost_opp);
}

int check_total(t_rcost cost)
{
    int total;

    total = 0;
    total = cost.ra + cost.rb + cost.rr;
    total = total + cost.rra + cost.rrb + cost.rrr;
    return (total);
}
//Case 0
t_rcost check_zero(s_pair *a, s_pair *b)
{
    t_rcost cost;

    cost = (t_rcost){0};
    if (a -> up == 0 || a -> down == 0)
    {
        if (b -> up <= b -> down)
            cost.rb = b -> up;
        else
            cost.rrb = b -> down;
    }
    else if (b -> up == 0 || b -> down == 0)
    {
        if (a -> up <= a -> down)
            cost.ra = a -> up;
        else
            cost.rra = a -> down;
    }
    cost.total = check_total(cost);
    return (cost);
}

t_rcost calculate_up_dir(int a, int b)
{
    t_rcost cost;

    cost = (t_rcost){0};
    if (a >= b)
    {
        cost.rr = b;
        cost.ra = a - b;
    }
    else if (b > a)
    {
        cost.rr = a;
        cost.rb = b - a;
    }
    cost.total = check_total(cost);
    return (cost);
}

t_rcost calculate_down_dir(int a, int b)
{
    t_rcost cost;

    cost = (t_rcost){0};
    if (a >= b)
    {
        cost.rrr = b;
        cost.rra = a - b;
    }
    else if (b > a)
    {
        cost.rrr = a;
        cost.rrb = b - a;
    }
    cost.total = check_total(cost);
    return (cost);
}
//Case 1
t_rcost check_same_dir_cost(s_pair *a, s_pair *b)
{
    t_rcost cost_up;
    t_rcost cost_down;

    cost_up = calculate_up_dir(a -> up, b -> up);
    cost_down = calculate_down_dir(a -> down,b -> down);
    if (cost_up.total <= cost_down.total)
        return (cost_up);
    else
        return (cost_down);
}
//Case 2
t_rcost check_opp_cost(s_pair *a, s_pair *b)
{
    t_rcost cost;

    cost = (t_rcost){0};
    if ((a -> up + b -> down) >= (a -> down + b -> up))
    {
        cost.ra = a -> up;
        cost.rrb = b -> down;
        cost.total = cost.ra + cost.rrb;
    }
    else
    {
        cost.rb = b -> up;
        cost.rra = a -> down;
        cost.total = cost.rb + cost.rra;
    }
    return (cost);
}
