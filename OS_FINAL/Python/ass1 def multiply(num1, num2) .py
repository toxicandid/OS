def multiply(num1, num2): 
  n1 = len(num1) 
  n2 = len(num2) 
  if (n1 == 0 or n2 == 0): 
    return "0" 
  # Will keep the result number in vector   # in reverse order 
  result = [0] * (n1 + n2) 
  # Below two indexes are used to 
  # find positions in result. 
  i_n1 = 0 
  i_n2 = 0 
  # Go from right to left in num1 
  for i in range(n1 - 1, -1, -1): 
    carry = 0 
    n_1 = ord(num1[i]) - ord('0') 
    # To shift position to left after every     # multiplication of a digit in num2     
    i_n2 = 0 
    # Go from right to left in num2 
    for j in range(n2 - 1, -1, -1): 
      # Take current digit of second number      
      n_2 = ord(num2[j]) - ord('0') 
      # Multiply with current digit of first number       # and add result to previously stored result       # at current position. 
      sum = n_1 * n_2 + result[i_n1 + i_n2] + carry 
      # Carry for next iteration 
      carry = sum // 10 
      # Store result 
      result[i_n1 + i_n2] = sum % 10 
      i_n2 += 1 
    # Store carry in next cell 
    if (carry > 0): 
      result[i_n1 + i_n2] += carry 
    # To shift position to left after every     # multiplication of a digit in num1.


    i_n1 += 1 
  # Ignore '0's from the right 
  i = len(result) - 1 


  i -= 1 
  # If all were '0's - means either both or   # one of num1 or num2 were '0' 
  if (i == -1): 
    return "0" 
  # Generate the result string 
  s = "" 
  while (i >= 0): 
    s += str(result[i]) 
    i -= 1 
  return s 
# Driver code 
if __name__ == "__main__": 
  str1 = "12345678901234567890" 
  print(multiply(str1, str1))