read n1
n2=0
n3=0
while  [ $n2 -le $n1 ]
    do
       let " n3 =  $n3 +  $n2 "
        let " n2 = $n2 + 1 "
   done
echo $n3
    
