# 算法

## RSA加密算法(人名)

<http://www.ruanyifeng.com/blog/2013/07/rsa_algorithm_part_two.html>

    "对极大整数做因数分解的难度决定了RSA算法的可靠性。换言之，对一极大整数做因数分解愈困难，RSA算法愈可靠。假如有人找到一种快速因数分解的算法，那么RSA的可靠性就会极度下降。但找到这样的算法的可能性是非常小的。今天只有短的RSA密钥才可能被暴力破解。到2008年为止，世界上还没有任何可靠的攻击RSA算法的方式。只要密钥长度足够长，用RSA加密的信息实际上是不能被解破的。"

## 加密算法

<https://blog.csdn.net/zuiyuezhou888/article/details/7557048>  
[Hash算法总结](https://www.jianshu.com/p/bf1d7eee28d0)

    对称加密：DES， AES(新)
    非对称加密：RSA， DSA(数字签名算法)，ECC(新)
    摘要算法：SHA1， MD5 --- SHA强度高，MD5速度快\

    一般来说，RSA建议采用1024位的数字，ECC建议采用160位，AES采用128为即可。在实际的操作过程中，我们通常采用的方式是：采用非对称加密算法管理对称算法的密钥，然后用对称加密算法加密数据，这样我们就集成了两类加密算法的优点，既实现了加密速度快的优点，又实现了安全方便管理密钥的优点。

## 大数据：查找，排序

## 游戏中的寻路算法

## Timsort()

<https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399>

## 压缩算法

### (1)无损压缩

+ Run-Length Encoding
+ Burrows-Wheeler Transform
+ Shannon-Fano Encoding
+ Huffman Encoding
+ Arithmetic Encoding

### (2)有损压缩

## Boyer-Moore Majority Vote algorithm
