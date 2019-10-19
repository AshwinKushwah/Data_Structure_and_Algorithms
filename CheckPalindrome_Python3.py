#python3 check palindrome
nums = input('Enter number:')
try:
    if nums == nums[::-1]:
        print(f'{nums} is PALINDROME number.')
    else: 
        print(f'{nums} is NOT PALINDROME number.')
except ValueError:
    print("Please Enter the number again.5")
