
print("welcome to jsinfinity  manager  what do you please choose a language \ntype 1 for english or 2 for french "
,"\n1-french \n2-english")


do
{
option=parseInt(input("entrez une option:"))
}while(option!=1)



if(option)
language="french"

if(language=="french")
{
print("bienvenue sur l'outils de gestion jsinfinity\n");
print("entrez --quit pour quitter ")
print("entrez --help pour avoir l'aide")
}
loop=true
while(loop)
{
    print("Commandes $ : ")
    c=input("").split(" ")
    command=c[0]
    if(command=="--quit")
    {
      loop=false
  
    }
    if(command=="version" || command=="--version")
    {
            Sys.version();
    }
    for(i=1;i<c.length;i++)
    {
        if(command=="runtest");
        if(command=="checktool");
        if(command=="getconfig");
        if(command=="setconfig");
       
        

    }
    

    
}
print("thanks for using jsinterpretor ")

