from sdes import SDES

class CRT:
    def __init__(self,counter):
        self.__counter = ''.join(counter)
        self.__empty_block = '00000000'
        self.__encrypter = SDES()
        self.__ciphered_blocks = []
    
    def __cipher_to_bin_list(self,cipher):
        a = []
        for i in cipher:
            new_component = str(bin(int(ord(i))))
            new_component = list(new_component.replace('b',''))
            while(len(new_component) < 8):
                new_component = ['0'] + new_component
            new_component = ''.join(new_component)
            a.append(new_component)
        return a

    def encrypt(self,cipher,key):
        for i in range(0,7):
            self.__encrypter.encrypt_byte(self.__counter[i:i+8],key)
        return

    def decrypt(self,cipher,key):
        print("====> Calling decrypt script !")
        if(len(cipher)%64 != 0):
            print('--------> not able to decrypt, not in correct format !')
            return

        blocks = [cipher[i:i+64] for i in range(0,len(cipher),64)]
        ciphers = []
        for i in blocks:
            ciphers.append([i[j:j+8] for j in range(0,len(i),8)])
        
        output = []
        for i in ciphers:
            for j in i:
                output.append(''.join(self.__encrypter.decrypt_byte(j,key)))

        return ''.join(output)
    
    def to_string(self,cipher):
        print("===> Calling to_string script !")
        output_string = []
        characters = [cipher[i:i+8] for i in range(0,len(cipher),8)]
        for i in characters:
            output_string.append(chr(int(i,2)))
        return ''.join(output_string)