# Simple Flush+Reload (Cache side-channel attack / Lab9)

This repository contains two proof-of-concept of cache side-channel attack (i.e., Flush+Reload). 
As all PoCs are only successfully mounted on Intel CPUs with Ubuntu, please checks your environment.
We demonstrated the demos in Ubuntu 20.04 LTS and Intel core i7-8700 3.20 GHz.

The prerequisite of Flush+Reload is memory sharing between spy and victim.
The PoC1 achieves this condition using <code>mmap()</code> and the PoC2 achieves this leveraging <code>dynamic shared library</code>.

<br>

## PoC1

The PoC1 probes that the victim accesses the specific target file (i.e., target.txt), repeatedly.
In this demo. the spy and victim achieve a memory sharing on *a target file*.

You can test this PoC1 codes in two ways.

### How to execute the PoC1 (victim: shell command)
<pre>
<code>
$ make

// spy
$ ./spy target.txt

// victim
$ cat target.txt
</code>
</pre>

### How to execute the PoC1 (victim: process)
<pre>
<code>
$ make

// spy
$ ./spy target.txt

// victim
$ ./victim target.txt
</code>
</pre>

<br>

## PoC2

The PoC2 observes the access patterns of victim on dynamic shared libs (i.e., libvul.so, libvul2.so), where spy figures out whether victim access specific target functions (e.g., add()) or not.
In this demo. the spy and victim achieve a memory sharing using *dynamic shared libs*.

### How to execute the PoC2
<pre>
<code>
$ make

// spy
$ ./spy

// victim
$ ./victim
</code>
</pre>

#### Notice

In the PoC2, we exploit the user-defined dynamic shared library for simplicity.
To successfully mount this demo, <u>you *must* copy the shared libs</u> (i.e., libvul.so, libvul2.so) on "/usr/lib/".

If you make your own dynamic shared lib, follow this steps.

#### How to make dynamic shared lib
<pre>
<code>
$ gcc -fPIC -c vul.c
$ gcc -shared -o libvul.so. vul.o

$ sudo cp libvul.so /usr/lib/
$ sudo ldconfig
</code>
</pre>


<br>

## Reference

**cacheutils.h** is based on [IAIK/flush_flush][iaikff]

[iaikff]: https://github.com/IAIK/flush_flush



