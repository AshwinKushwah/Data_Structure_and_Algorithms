
/**
 * Write a description of class Number_System here.
 * The program can check whether a number in their respective number system is valid or not.
 * it also can change a number from one number system to the other.
 * 
 * @author (your name) :- Eeshan Dutta
 * @version (a version number or a date) :- 21st May,2017
 */
import java.util.Scanner;
public class Number_System
{
    public static void main (String args[])
    {
        Scanner sc = new Scanner (System.in);
        System.out.print("\f\nEnter a number :- ");
        String a=sc.nextLine().toUpperCase();
        System.out.print("\nEnter the base of the number :- ");
        int b=sc.nextInt();
        if(!(b==2||b==8||b==10||b==16))
        {
            System.out.print("\nWrong input of base!");
            return;
        }
        Number_System obj = new Number_System();
        if(obj.check(a,b)==true)
            System.out.println("\nValid number!");
        else
        {
            System.out.print("\nNot a Valid Number!");
            return;
        }
        System.out.print("\nEnter the base of the number to which u want to convert :- ");
        int c=sc.nextInt();
        if(!(c==2||c==8||c==10||c==16))
        {
            System.out.print("\nWrong input of base!");
            return;
        }
        if(c==b)
            System.out.print("\nThe number in base "+c+" = "+a);
        else if(b==2 && c==8)
            System.out.print("\nThe number in Octal Number System = "+obj.Binary_to_Octal(a));
        else if(b==2 && c==10)
            obj.Binary_to_Decimal(a);
        else if(b==2 && c==16)
            System.out.print("\nThe number in Hexadecimal Number System = "+obj.Binary_to_Hexadecimal(a));
        else if(b==10 && c==2)
            obj.Decimal_to_Binary(a);
        else if(b==10 && c==8)
            obj.Decimal_to_Octal(a);
        else if(b==10 && c==16)
            obj.Decimal_to_Hexadecimal(a);
        else if(b==8 && c==2)
            System.out.print("\nThe number in Binary Number System = "+obj.Octal_to_Binary(a));
        else if(b==8 && c==10)
            obj.Octal_to_Decimal(a);
        else if(b==8 && c==16)
            System.out.print("\nThe number in Hexadecimal Number System = "+obj.Binary_to_Hexadecimal(obj.Octal_to_Binary(a)));
        else if(b==16 && c==2)
            System.out.print("\nThe number in Binary Number System = "+obj.Hexadecimal_to_Binary(a));
        else if(b==16 && c==10)
            obj.Hexadecimal_to_Decimal(a);
        else if(b==16 && c==8)
            System.out.print("\nThe number in Octal Number System = "+obj.Binary_to_Octal(obj.Hexadecimal_to_Binary(a)));
        else
            System.out.print("\nNot Valid Transformation!");
    }

    public boolean check(String a,int b)
    {
        for(int i=0;i<a.length();i++)
        {
            char c=a.charAt(i);
            if(c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F')
                c-=7;
            if((c-'0')>=b)
                return false;
        }
        return true;
    }

    public String Binary_to_Octal(String a)
    { 
        int i,k,d,r,s=0,g=0;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        for(i=f.length()%3;i<3 && i>0;i++)
            f="0"+f;
        k=Integer.parseInt(f);
        for(i=0;k>0;k/=1000,i++)
        {
            d=k%1000;
            r=d%10+((d%100)/10)*2+(d/100)*4;
            s+=r*(Math.pow(10,i));
        }
        f=Integer.toString(s);
        if(l.equals("0"))
            return f;
        else
        {
            for(i=l.length()%3;i<3;i++)
                l+="0";
            k=Integer.parseInt(l);
            for(i=0;k>0;k/=1000,i++)
            {
                d=k%1000;
                r=d%10+((d%100)/10)*2+(d/100)*4;
                g+=r*(Math.pow(10,i));
            }
            l=Integer.toString(g);
            return(f+"."+l);
        }
    }

    public boolean SP(String a)
    {
        for(int i=0;i<a.length();i++)
        {
            char c=a.charAt(i);
            if(c=='.')
                return true;
        }
        return false;
    }

    public int Palindrome(int a)
    {
        int f=0;
        for(;a>0;a/=10)
            f=f*10+(a%10);
        return f;
    }

    public String Palindrome(String a)
    {
        String b="";
        for(int i=a.length()-1;i>=0;i--)
            b+=a.charAt(i);
        return b;    
    }

    public void Binary_to_Decimal(String a)
    {
        int i,p,d=0;double k=0.0;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        for(p=0,i=Integer.parseInt(f);i>0;i/=10,p++) 
            d+=(i%10)*Math.pow(2,p);
        if(l.equals("0"))
            System.out.print("\nThe number in Decimal Number System = "+d);
        else
        {
            for(i=0,p=-1;i<l.length();i++,p--)
            {
                if(l.charAt(i)=='1')
                    k+=Math.pow(2,p);    
            }
            System.out.print("\nThe number in Decimal Number System = "+(k+d));    
        }
    }

    public String Binary_to_Hexadecimal(String a)
    {
        char c[]={'A','B','C','D','E','F'};
        int i,d,r,k;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        for(i=f.length()%4;i<4 && i>0;i++)
            f="0"+f;    
        k=Integer.parseInt(f);f="";
        for(i=0;k>0;k/=10000,i++)
        {
            d=k%10000;
            r=d%10+((d%100)/10)*2+((d%1000)/100)*4+(d/1000)*8;
            if(r>=10)
                f=c[r-10]+f;
            else
                f=r+f;  
        }
        if(l.equals("0"))
            return f;
        else
        {
            for(i=l.length()%4;i<4 && i>0;i++)
                l+="0";
            k=Integer.parseInt(l);l="";
            for(i=0;k>0;k/=10000,i++)
            {
                d=k%10000;
                r=d%10+((d%100)/10)*2+((d%1000)/100)*4+(d/1000)*8;
                if(r>=10)
                    l=c[r-10]+l;
                else
                    l=r+l;
            }
            return(f+"."+l);
        }
    }

    public void Decimal_to_Binary(String a)
    {
        int i,k;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        k=Integer.parseInt(f);f="";
        for(;k>0;k/=2)
            f+=k%2;
        if(l.equals("0"))
            System.out.print("\nThe number in Binary Number System = "+Palindrome(f));
        else
        {
            k=Integer.parseInt(l);String m="";
            for(i=1;i<=4;i++)
            {
                k*=2;
                m+=(int)(k/Math.pow(10,l.length()));
                k%=Math.pow(10,l.length());
            }
            System.out.print("\nThe number in Binary Number System = "+Palindrome(f)+"."+m);
        }
    }

    public void Decimal_to_Octal(String a)
    {
        int i,k;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        k=Integer.parseInt(f);f="";
        for(;k>0;k/=8)
            f+=k%8;
        if(l.equals("0"))
            System.out.print("\nThe number in Octal Number System = "+Palindrome(f));
        else
        {
            k=Integer.parseInt(l);String m="";
            for(i=1;i<=4;i++)
            {
                k*=8;
                m+=(int)(k/Math.pow(10,l.length()));
                k%=Math.pow(10,l.length());
            }
            System.out.print("\nThe number in Octal Number System = "+Palindrome(f)+"."+m);
        }
    }

    public void Decimal_to_Hexadecimal(String a)
    {
        char c[]={'A','B','C','D','E','F'};
        int i,k,s;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        k=Integer.parseInt(f);f="";
        for(;k>0;k/=16)
        {
            s=k%16;
            if(s<10)
                f+=s;
            else
                f+=c[s-10];
        }
        if(l.equals("0"))
            System.out.print("\nThe number in Hexadecimal Number System = "+Palindrome(f));
        else
        {
            k=Integer.parseInt(l);String m="";
            for(i=1;i<=4;i++)
            {
                k*=16;
                s=(int)(k/Math.pow(10,l.length()));
                if(s<10)
                    m+=s;
                else
                    m+=c[s-10];
                k%=Math.pow(10,l.length());
            }
            System.out.print("\nThe number in Hexadecimal Number System = "+Palindrome(f)+"."+m);
        }
    }

    public String Octal_to_Binary(String a)
    {
        int i,k,s,p;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        k=Integer.parseInt(f);f="";
        for(;k>0;k/=10)
        {
            s=k%10;
            for(p=s;s>0;s/=2)
                f=s%2+f;
            if(p!=0)
            {
                for(i=f.length()%3;i<3 && i>0;i++)
                    f="0"+f;
            }
            else
            {
                for(i=f.length()%3;i<3 && i>=0;i++)
                    f="0"+f;
            }
        }
        if(l.equals("0"))
            return f;
        else
        {
            k=Integer.parseInt(l);l="";
            for(;k>0;k/=10)
            {
                s=k%10;
                for(p=s;s>0;s/=2)
                    l+=s%2; 
                if(p!=0)
                {
                    for(i=l.length()%3;i<3 && i>0;i++)
                        l=l+"0";
                }
                else
                {
                    for(i=l.length()%3;i<3 && i>=0;i++)
                        l=l+"0";
                }
            }
            return(f+"."+Palindrome(l));
        }
    }

    public void Octal_to_Decimal(String a)
    {
        int j,i,p,d=0;double k=0.0;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        for(p=0,i=Integer.parseInt(f);i>0;i/=10,p++) 
            d+=(i%10)*Math.pow(8,p);
        if(l.equals("0"))
            System.out.print("\nThe number in Decimal Number System = "+d);
        else
        {
            j=Integer.parseInt(l);
            j=Palindrome(j);
            for(i=0,p=-1;i<l.length();i++,p--,j/=10)
                k+=(j%10)*Math.pow(8,p);    
            System.out.print("\nThe number in Decimal Number System = "+(k+d));    
        }
    }

    public String Hexadecimal_to_Binary(String a)
    {
        char c[]={'A','B','C','D','E','F'};
        int i,k,s,t,p;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.')),o="";
        String l=a.substring(a.indexOf('.')+1),m="";
        for(i=f.length()-1;i>=0;i--)
        {
            char d=f.charAt(i);
            if(Character.isLetter(d))
                t=d-(48+7);
            else
                t=d-48; 
            if(Character.isLetter(d))
                s=(int)t%100;
            else
                s=(int)t%10;
            for(p=s;s>0;s/=2)
                o=s%2+o;
            if(p==0)
            {
                for(k=o.length()%4;k<4 && k>=0;k++)
                    o="0"+o;
            }
            else
            {
                for(k=o.length()%4;k<4 && k>0;k++)
                    o="0"+o;
            }
        }
        if(l.equals("0"))
            return o;
        else
        {
            for(i=l.length()-1;i>=0;i--)
            {
                char d=l.charAt(i);
                if(Character.isLetter(d))
                    t=d-(48+7);
                else
                    t=d-48; 
                if(Character.isLetter(d))
                    s=(int)t%100;
                else
                    s=(int)t%10;
                for(p=s;s>0;s/=2)
                    m=s%2+m;
                if(p!=0)
                {
                    for(k=m.length()%4;k<4 && k>0;k++)
                        m="0"+m;
                }
                else
                {
                    for(k=m.length()%4;k<4 && k>=0;k++)
                        m="0"+m;
                }
            }
            return(o+"."+m);
        }
    }

    public void Hexadecimal_to_Decimal(String a)
    {
        int i,p,d=0,t,s,c;double k=0.0;
        if(SP(a)==false)
            a+=".0";
        String f=a.substring(0,a.indexOf('.'));
        String l=a.substring(a.indexOf('.')+1);
        for(i=f.length()-1,p=0;i>=0;i--,p++)
        {
            char u=f.charAt(i);
            if(Character.isLetter(u))
                t=u-(48+7);
            else
                t=u-48; 
            d+=t*(Math.pow(16,p));  
        }
        if(l.equals("0"))
            System.out.print("\nThe number in Decimal Number System = "+d);
        else
        {
            for(i=0,p=-1;i<l.length();i++,p--)
            {
                char u=l.charAt(i);
                if(Character.isLetter(u))
                    t=u-(48+7);
                else
                    t=u-48; 
                k+=t*(Math.pow(16,p));  
            }
            System.out.print("\nThe number in Decimal Number System = "+(k+d));
        }
    }
}