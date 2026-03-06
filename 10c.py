from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import utils
private_key = dsa.generate_private_key(key_size=1024)
public_key = private_key.public_key()
message = input("Enter message: ").encode()
signature = private_key.sign(message, hashes.SHA256())
print("Digital Signature:", signature)
try:
    public_key.verify(signature, message, hashes.SHA256())
    print("Signature Verified")
except:
    print("Signature Verification Failed")