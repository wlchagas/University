from random import randint

from ecb import ECB
from cbc import CBC
from crt import CRT



key = "00011100000111000001110000011100000111000001110000111000"
cipher = "you can write w/e you want"

cryp_ecb = False
cryp_cbc = False
cryp_crt = True
if(cryp_ecb):
    print('----==== ECB RUNNING ====----')
    ecb = ECB()
    encrypted = ecb.encrypt(cipher,key)
    # print(encrypted)
    decrypted = ecb.decrypt(encrypted,key)
    # print(decrypted)
    to_string = ecb.to_string(decrypted)
    # print(to_string)

if(cryp_cbc):
    print('----==== CBC RUNNING ====----')
    # IV = [str(randint(0,1)) for _ in range(0,64)]
    IV = "0001110000011100000111000001110000011100000111000011100000111000"
    cbc = CBC()
    encrypted = cbc.encrypt(cipher,key,IV)
    # print(encrypted)
    decrypted = cbc.decrypt(encrypted,key,IV)
    # print(decrypted)
    to_string = cbc.to_string(decrypted)
    print(to_string)

if(cryp_crt):
    print('----==== CRT RUNNING ====----')
    counter = [str(randint(0,1)) for _ in range(0,56)]
    crt = CRT(counter)
    encrypted = crt.encrypt(cipher,key)
    