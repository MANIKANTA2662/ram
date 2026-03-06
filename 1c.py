text = input("Enter the message: ")
shift = int(input("Enter the shift value: "))

result = ""

for char in text:
    if char.isalpha():
        if char.islower():
            result += chr((ord(char) - 97 + shift) % 26 + 97)
        else:
            result += chr((ord(char) - 65 + shift) % 26 + 65)
    else:
        result += char

print("Encrypted Message:", result)