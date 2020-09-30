
/**
 * Write a description of class Sudoku_Solver here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.util.Scanner;
public class Sudoku_Solver
{
    int a[][];
    public Sudoku_Solver()
    {
        a=new int[9][9];
    }

    public void input()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("\f\nInput the given details (give 0 to the spaces) :- ");
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                if(sc.hasNextInt())
                    a[i][j]=sc.nextInt();
            System.out.println();
        }
    }

    public boolean isSafe(int i,int r,int c)
    {
        for(int j=0;j<9;j++)
        {
            if(a[j][c]==i)
                return false;
            if(a[r][j]==i)
                return false;
        }
        int r1=r-r%3;
        int c1=c-c%3;
        for(int t=r1;t<r1+3;t++)
            for(int k=c1;k<c1+3;k++)
                if(a[r1][k]==i)
                    return false;
        return true;
    }

    public boolean Solve()
    {
        int r=0,c=0,i=0,j=0;boolean Empty=false;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(a[i][j]==0)
                {
                    r=i;
                    c=j;
                    Empty = true;
                    break;
                }
            }
            if(Empty)
                break;
        }
        if(Empty==false)
            return true;
        for(int l=1;l<=9;l++)
        {
            if(isSafe(l,r,c))
            {   
                a[r][c]=l;    
                if(Solve())
                    return true;
                else
                    a[r][c]=0;
            }
        }
        return false;
    }

    public void print()
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                System.out.print(a[i][j]+" ");
            System.out.println();
        }
    }

    public static void main(String args[])
    {
        Sudoku_Solver obj = new Sudoku_Solver();
        obj.input();
        if(obj.Solve())
            obj.print();
        else
            System.out.print("\nSudoku cannot be solved!");
    }
}
