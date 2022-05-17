


print("vous pouvez creez un nouveau environnement virtuel avec vitualenv")

loop=true
do
{
    print("Commandes $ : ")
    c=input("").split(" ")
    command=c[0]
    if(command=="--quit")
    {
      loop=false
    }
    if( command=="--help")
    {
          print("\n--create : permet de creer un nouvel environnement virtuel",
          "\n--relocate : permet de modifier  environnement virtuel permet de ",
          "\n--getlast recupere les envirronement virtuel precedemment creer",
          
          "\n")
    }
    for(i=1;i<c.length;i++)
    {
     
        if(command=="checktool");
        if(command=="getconfig");
        if(command=="setconfig");             
}  
}while(loop)
print("thanks for using jsinterpretor ")


