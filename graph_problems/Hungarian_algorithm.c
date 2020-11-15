#include <stdio.h>
#include <stdlib.h>

#define true        1
#define false       0

#define marked      1
#define unmarked    0

#define unit        long long int
void display (unit **A, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++, printf("\n"))
        for (j = 0; j < col; j++)
            printf("%lld ", A[i][j]);
}

void display2 (int **A, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++, printf("\n"))
        for (j = 0; j < col; j++)
            printf("%d ", A[i][j]);
}

void get_Matrix_entry (unit **A, unit **B, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            scanf("%lld", &A[i][j]);
            B[i][j] = A[i][j];
        }
}

/* At the first time, need to find out the maximum value of each row */
void find_Row_Maximum (unit **ori, unit *row_record, int row, int col)
{
    int i, j;
    unit Max = 0;
    for(i = 0; i < row; i++)
    {
        Max = ori[i][0];
        for(j = 1; j < col; j++)
            if(ori[i][j] > Max)
                Max = ori[i][j];
        row_record[i] = Max;
    }
}

/* Find minimum vertex cover and return true, when 
 * find out that every row has a unique vertex.
 */
int Hungarian_isDone (unit **ori, int *min_cover_row, int *min_cover_col, int row, int col)
{
    int i, j, count = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j ++)
        {
            if(ori[i][j])
                if(!min_cover_row[i] && !min_cover_col[j])
                    return false;
        }
    }
    return true;
}

void Set_zero_edge (unit **job, int **edge, int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
        {
            if(job[i][j] == 0)
                edge[i][j] = 1;
            else
                edge[i][j] = 0;
        }
    
}

int All_S_marked(int *S, int *row_marked, int row)
{
    int i;
    for(i = 0; i < row; i++)
    {
        if(S[i] && !row_marked[i])
            return false;
    }
    return true;
}

/* recursively find for argumenting path, and reverse if needed */
int explore (unit **ori, int **edge, int **Max_matching, int *row_marked, int *col_marked, int *S, int *T, int row, int col, int index)
{
    int i, j, can_matching, need_matching, Max_unsaturated_vertex;
    unit Max_unsaturated_value = -1;

    row_marked[index] = marked;
    can_matching = false;               // means whether can find an unsaturated vertex
    need_matching = false;

    for(j = 0; j < col; j++)
    {
        if(edge[index][j] && col_marked[j] == false)
        {
            can_matching = true;
            for(i = 0; i < row; i++)
            {
                if(Max_matching[i][j])
                {
                    S[i] = true;
                    T[j] = true;
                    row_marked[i] = true;
                    col_marked[j] = true;
                    can_matching = false;
                    if(explore(ori, edge, Max_matching, row_marked, col_marked, S, T, row, col, i))    // when need reverse
                    {
                        S[index] = 0;
                        T[j] = true;
                        Max_matching[i][j] = false;
                        Max_matching[index][j] = true;
                        return true;
                    }
                }
            }

            if(can_matching && ori[index][j] > Max_unsaturated_value)            // find an unsaturated vertex
            {
                need_matching = true;
                Max_unsaturated_vertex = j;
                Max_unsaturated_value = ori[index][j];
            }
        }
    }
    if(need_matching)
    {
        S[index] = 0;                               // remove vertex in S
        T[Max_unsaturated_vertex] = true;           // put unsaturated vertex to T
        Max_matching[index][Max_unsaturated_vertex] = 1;
        return true;
    }
    return false;
}

int find_argument_path (unit **ori, int **edge, int **Max_matching, int *row_marked, int *col_marked, int *S, int *T, int row, int col, int index)
{
    int i, j, can_matching, need_matching, Max_unsaturated_vertex;
    unit Max_unsaturated_value = -1;

    row_marked[index] = marked;
    can_matching = false;               // means whether can find an unsaturated vertex
    need_matching = false;

    for(j = 0; j < col; j++)
    {
        if(edge[index][j])
        {
            can_matching = true;
            for(i = 0; i < row; i++)    // determine is the vertex in Y matched
            {
                if(Max_matching[i][j])
                {
                    can_matching = false;
                    break;
                }
            }

            if(can_matching && ori[index][j] > Max_unsaturated_value)            // find an unsaturated vertex
            {
                need_matching = true;
                Max_unsaturated_vertex = j;
                Max_unsaturated_value = ori[index][j];
            }
        }
    }
    if(need_matching)
    {
        S[index] = 0;                               // remove vertex in S
        T[Max_unsaturated_vertex] = true;           // put unsaturated vertex to T
        Max_matching[index][Max_unsaturated_vertex] = 1;
        return true;
    }
    return explore(ori, edge, Max_matching, row_marked, col_marked, S, T, row, col, index);
}

void min_vertex_cover (unit **ori, int **edge, int **Max_matching, int *min_cover_row, int *min_cover_col, int *row_marked, int *col_marked, int *S, int *T, int row, int col)
{
    int i, j, next_loop;
    
    while(1)
    {
        next_loop = false;
        for(i = 0; i < row; i++)
            row_marked[i] = unmarked;
        for(j = 0; j < col; j++)
        {
            T[j] = false;
            col_marked[j] = unmarked;
        }
        for(i = 0; i < row; i++)
        {
            if(S[i] == true && row_marked[i] == unmarked)       // find argumenting path of an unmarked vertex in S
            {
                /* Return true when find a path, and then iterating.
                 * Otherwise, it would return false whitch means that
                 * need start with other vertex or finished.
                 */
                if(find_argument_path(ori, edge, Max_matching, row_marked, col_marked, S, T, row, col, i))     
                {
                    S[i] = false;
                    next_loop = true;
                    // printf("iteration %d\n", i);
                    // display(edge, row, col);
                    // printf("\n");
                    // display(Max_matching, row, col);
                    break;
                }
                // printf("iteration %d\n", i);
                // display(edge, row, col);
                // printf("\n");
                // display(Max_matching, row, col);
            }
        }

        if(next_loop == false && All_S_marked(S, row_marked, row))
            break;
    }
    for(i = 0; i < row; i++)
        if(!S[i])
            min_cover_row[i] = true;
    for(j = 0; j < col; j++)
        if(T[j])
            min_cover_col[j] = true;
}

void adjust_Matrix (unit **ori, unit **job, int **Maximum_matching, unit *row_record, unit *col_record, int *min_cover_row, int *min_cover_col, int row, int col)
{
    int i, j;
    unit min = 0x7FFFFFFFFFFFFFFF;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            if(!min_cover_row[i] && !min_cover_col[j] && job[i][j] < min)
                min = job[i][j];

    for(i = 0; i < row; i++)
        if(!min_cover_row[i])
            row_record[i] -= min;
    
    for(j = 0; j < col; j++)
        if(min_cover_col[j])
            col_record[j] += min;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            job[i][j] = row_record[i] + col_record[j] - ori[i][j];
    
    // for(i = 0; i < row; i++)
    //     printf("%d ", row_record[i]);
    // printf("\n");
    // for(j = 0; j < col; j++)
    //     printf("%d ", col_record[j]);
    // printf("\n");

    // display(job, row, col);
    // printf("\n");
}

unit get_Maximum_weight(unit **ori, int **Maximum_matching, int row, int col) {
    int i, j;
    unit ret = 0;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            if(Maximum_matching[i][j])
                ret += ori[i][j];
    return ret;
}

void Hungarian (unit **ori, unit **job, int row, int col)
{
    int i, j;
    /* record the maximum value for each vertex */
    unit *row_record = (unit *)malloc(row * sizeof(unit));
    unit *col_record = (unit *)malloc(col * sizeof(unit));

    /* used in finding minimum vertex cover */
    int *row_marked = (int *)malloc(row * sizeof(int));
    int *col_marked = (int *)malloc(col * sizeof(int));
    int *min_cover_row = (int *)malloc(row * sizeof(int));      
    int *min_cover_col = (int *)malloc(col * sizeof(int));
    int *S = (int *)malloc(row * sizeof(int));      
    int *T = (int *)malloc(col * sizeof(int));
    int **Matrix_zero_edge;
    int **Maximum_matching;

    Matrix_zero_edge = (int **)malloc(row * sizeof(int *));
    Maximum_matching = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < col; i++)
    {
        Matrix_zero_edge[i] = (int *)malloc(col * sizeof(int));
        Maximum_matching[i] = (int *)malloc(col * sizeof(int));
    }
        
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            Matrix_zero_edge[i][j] = 0;
            Maximum_matching[i][j] = 0;
        }
    find_Row_Maximum(ori, row_record, row, col);
    for(i = 0; i < col; i++)
    {
        col_record[i] = 0;
        min_cover_col[i] = 0;
        T[i] = 0;
    }
    for(i = 0; i < col; i++)
    {
        min_cover_row[i] = 0;
        S[i] = 0;
    }

    while (!Hungarian_isDone(ori, min_cover_row, min_cover_col, row, col))
    {
        /* reset value for every iteration */
        for(i = 0; i < row; i++)
        {
            row_marked[i] = unmarked;
            min_cover_row[i] = 0;
            S[i] = 1;
        }
        for(i = 0; i < col; i++)
        {
            col_marked[i] = unmarked;
            min_cover_col[i] = 0;
            T[i] = 0;
        }

        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
            {
                job[i][j] = row_record[i] + col_record[j] - ori[i][j];      // compute new value for each edge
                Maximum_matching[i][j] = 0;                                 // reset
            }
        // for(i = 0; i < row; i++)
        //     printf("%d ", row_record[i]);
        // printf("\n");
        // for(j = 0; j < col; j++)
        //     printf("%d ", col_record[j]);
        // printf("\n");
        Set_zero_edge(job, Matrix_zero_edge, row, col);
        // display(job, row, col);
        min_vertex_cover(ori, Matrix_zero_edge, Maximum_matching, min_cover_row, min_cover_col, 
            row_marked, col_marked, S, T, row, col);
        // for(i = 0; i < row; i++)
        //     printf("%d ", min_cover_row[i]);
        // printf("\n");
        // for(j = 0; j < col; j++)
        //     printf("%d ", min_cover_col[j]);
        // printf("\n");
        adjust_Matrix(ori, job, Maximum_matching, row_record, col_record, min_cover_row, min_cover_col, row, col);
        // break;
        // find lowest value and set col_record
    }
    printf("\nMaximum matching:\n");
    display2(Maximum_matching, row, col);
    unit sum = get_Maximum_weight(ori, Maximum_matching, row, col);
    printf("\nSum of Maximum matching is %lld.", sum);
}

int main()
{
    // printf("dsadas\n");
    int M_size, i, j, row, col;
    // scanf("%d", &row);
    // scanf("%d", &col);
    scanf("%d", &M_size);
    row = M_size;
    col = M_size;
    unit **orig_Matrix, **job_Matrix;
    orig_Matrix = (unit **)malloc(row * sizeof(unit *));
    job_Matrix = (unit **)malloc(row * sizeof(unit *));
    for (i = 0; i < col; i++)
    {
        orig_Matrix[i] = (unit *)malloc(col * sizeof(unit));
        job_Matrix[i] = (unit *)malloc(col * sizeof(unit));
    }
    get_Matrix_entry(orig_Matrix, job_Matrix, row, col);
    printf("Input:\n");
    display(job_Matrix, row, col);
    // printf("\n");
    Hungarian(orig_Matrix, job_Matrix, row, col);
    

    return 0;
}
