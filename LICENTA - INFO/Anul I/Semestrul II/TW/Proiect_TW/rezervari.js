let rezervare1 = document.getElementById("b1");
let rezervare2 = document.getElementById("b2");
let rezervare4 = document.getElementById("b3");
let rezervare3 = document.getElementById("b4");
let rezervare5 = document.getElementById("b5");
let rezervare6 = document.getElementById("b6");
let rezervare7 = document.getElementById("b7");
var id=0;

rezervare1.addEventListener("click", function(){
    
    let ok=false;
    let div=document.getElementById("mainContainer");
    let div1=document.getElementById("textBox");
    let text = document.createElement("p");
    text.innerText = "Ati ales sa faceti o rezervare in timpul sezonului! Alegeti datele!";
    let div2=document.getElementById("inputsContainer");
    let ul=document.createElement("ul");
    let li1=document.createElement("li");
    let li2=document.createElement("li");
    li1.innerText="Alegeti Data";
    li2.innerText="Alegeti Numarul de persoane"
    let input1=document.createElement("input");
    input1.type="date";
    let input2=document.createElement("input");
    input2.type="number";
    let div3=document.getElementById("confirmationContainer");
    let buton1=document.createElement("button");
    let buton2=document.createElement("button");
    buton1.innerText="Confirmati rezervarea!";
    buton2.innerText="Rezervare noua";

    li1.appendChild(input1);
    li2.appendChild(input2);

    ul.appendChild(li1);
    ul.appendChild(li2);

    div1.appendChild(text);
    div2.appendChild(ul);
    div3.appendChild(buton1);
    div3.appendChild(buton2);

    div.appendChild(div1);
    div.appendChild(div2);
    div.appendChild(div3);

    buton1.addEventListener("click", function(){
        let div4=document.createElement("div");
        let text1=document.createElement("p");
        text1.innerText="Rezervarea pentru "+input2.value+" persoane in data de "+input1.value+" a fost confirmata!"
        div4.appendChild(text1);
        div.appendChild(div4);
        ok=true;


        var numar=input2.value;
        var data=input1.value;
        var cod=1;
        var rezervareTip1 = {
            numarPersoane : numar,
            dataRezervata : data,
            tip : "sezon",
            cod : cod
        };
        
        fetch('http://localhost:3000/tip1', {
            method: 'post', 
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(rezervareTip1)
        }).then(function(response) {
        console.log(response);
        })
        id+=1;
        

        

    })

    buton2.addEventListener("click", function(){
        li1.removeChild(input1);
        li2.removeChild(input2);
        ul.removeChild(li1);
        ul.removeChild(li2);
        div1.removeChild(text);
        div2.removeChild(ul);
        div3.removeChild(buton1);
        div3.removeChild(buton2);
        if (ok==true)
        {
            document.location.reload();
        }
    })
})

rezervare2.addEventListener("click", function(){
    
    let ok=false;
    let div=document.getElementById("mainContainer");
    let div1=document.getElementById("textBox");
    let text = document.createElement("p");
    text.innerText = "Ati ales sa faceti o rezervare in extra-sezon! Alegeti datele!";
    let div2=document.getElementById("inputsContainer");
    let ul=document.createElement("ul");
    let li1=document.createElement("li");
    let li2=document.createElement("li");
    li1.innerText="Alegeti Data";
    li2.innerText="Alegeti Numarul de persoane"
    let input1=document.createElement("input");
    input1.type="date";
    let input2=document.createElement("input");
    input2.type="number";
    let div3=document.getElementById("confirmationContainer");
    let buton1=document.createElement("button");
    let buton2=document.createElement("button");
    buton1.innerText="Confirmati rezervarea!";
    buton2.innerText="Rezervare noua!";

    li1.appendChild(input1);
    li2.appendChild(input2);

    ul.appendChild(li1);
    ul.appendChild(li2);

    div1.appendChild(text);
    div2.appendChild(ul);
    div3.appendChild(buton1);
    div3.appendChild(buton2);

    div.appendChild(div1);
    div.appendChild(div2);
    div.appendChild(div3);

    buton1.addEventListener("click", function(){
        let div4=document.createElement("div");
        let text1=document.createElement("p");
        text1.innerText="Rezervarea pentru "+input2.value+" persoane in data de "+input1.value+" a fost confirmata!"
        div4.appendChild(text1);
        div.appendChild(div4);
        ok=true;

        var numar=input2.value;
        var data=input1.value;
        var cod=2;
        var rezervareTip1 = {
            numarPersoane : numar,
            dataRezervata : data,
            tip : "extra-sezon",
            cod:cod
        };

        fetch('http://localhost:3000/tip1', {
            method: 'post', 
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(rezervareTip1)
        }).then(function(response) {
        console.log(response);
        })
        id+=1;
    })

    buton2.addEventListener("click", function(){
        li1.removeChild(input1);
        li2.removeChild(input2);
        ul.removeChild(li1);
        ul.removeChild(li2);
        div1.removeChild(text);
        div2.removeChild(ul);
        div3.removeChild(buton1);
        div3.removeChild(buton2);
        if (ok==true)
        {
            document.location.reload();
        }
    })
})


rezervare3.addEventListener("click", function(){
    
    let ok=false;
    let div=document.getElementById("mainContainer");
    let div1=document.getElementById("textBox");
    let text = document.createElement("p");
    text.innerText = "Ati ales sa Rezervati un loc intr-o tabara! Alegeti datele!";
    let div2=document.getElementById("inputsContainer");
    let ul=document.createElement("ul");
    let li1=document.createElement("li");
    let li2=document.createElement("li");
    let li3=document.createElement("li");
    li1.innerText="Alegeti Perioada";
    li3.innerText="Alegeti Seria";
    li2.innerText="Alegeti Numarul de persoane";
    let input1=document.createElement("select");
    let opt1=document.createElement("option");
    let opt2=document.createElement("option");
    opt1.innerText="Sezon";
    opt2.innerText="Extra-Sezon";
    let input3=document.createElement("select");
    let opt3=document.createElement("option");
    let opt4=document.createElement("option");
    let opt5=document.createElement("option");
    let opt6=document.createElement("option");
    let opt7=document.createElement("option");
    let opt8=document.createElement("option");
    opt3.innerText="Seria 1";
    opt4.innerText="Seria 2";
    opt5.innerText="Seria 3";
    opt6.innerText="Seria 4";
    opt7.innerText="Seria 5";
    opt8.innerText="Seria 6";
    let input2=document.createElement("input");
    input2.type="number";
    let div3=document.getElementById("confirmationContainer");
    let buton1=document.createElement("button");
    let buton2=document.createElement("button");
    buton1.innerText="Confirmati rezervarea!";
    buton2.innerText="Rezervare Noua!";

    input1.appendChild(opt1);
    input1.appendChild(opt2);

    input3.appendChild(opt3);
    input3.appendChild(opt4);
    input3.appendChild(opt5);
    input3.appendChild(opt6);
    input3.appendChild(opt7);
    input3.appendChild(opt8);

    li1.appendChild(input1);
    li3.appendChild(input3);
    li2.appendChild(input2);

    ul.appendChild(li1);
    ul.appendChild(li3);
    ul.appendChild(li2);

    div1.appendChild(text);
    div2.appendChild(ul);
    div3.appendChild(buton1);
    div3.appendChild(buton2);

    div.appendChild(div1);
    div.appendChild(div2);
    div.appendChild(div3);

    buton1.addEventListener("click", function(){
        let div4=document.createElement("div");
        let text1=document.createElement("p");
        text1.innerText="Rezervarea pentru "+input2.value+" persoane in perioada de "+input1.value+" in "+input3.value+" a fost confirmata!";
        div4.appendChild(text1);
        div.appendChild(div4);
        ok=true;

        var numar=input2.value;
        var data=input3.value;
        var serie=input1.value;
        var cod=3;
        var rezervareTip1 = {
            numarPersoane : numar,
            dataRezervata : serie,
            tip : data,
            cod:cod
        };

        fetch('http://localhost:3000/tip1', {
            method: 'post', 
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(rezervareTip1)
        }).then(function(response) {
        console.log(response);
        })
        id+=1;
    })

    buton2.addEventListener("click", function(){
        li1.removeChild(input1);
        li2.removeChild(input2);
        ul.removeChild(li1);
        ul.removeChild(li2);
        div1.removeChild(text);
        div2.removeChild(ul);
        div3.removeChild(buton1);
        div3.removeChild(buton2);
        if (ok==true)
        {
            document.location.reload();
        }
    })
})

rezervare4.addEventListener("click", function(){
    
    let ok=false;
    let div=document.getElementById("mainContainer");
    let div1=document.getElementById("textBox");
    let text = document.createElement("p");
    text.innerText = "Ati ales sa Rezervati un loc intr-o tabara din Austria! Alegeti datele!";
    let div2=document.getElementById("inputsContainer");
    let ul=document.createElement("ul");
    
    let li2=document.createElement("li");
    let li3=document.createElement("li");
    
    li3.innerText="Alegeti Seria";
    li2.innerText="Alegeti Numarul de persoane";
    
    
    let input3=document.createElement("select");
    let opt3=document.createElement("option");
    let opt4=document.createElement("option");
    
    opt3.innerText="Seria 1";
    opt4.innerText="Seria 2";
    
    let input2=document.createElement("input");
    input2.type="number";
    let div3=document.getElementById("confirmationContainer");
    let buton1=document.createElement("button");
    let buton2=document.createElement("button");
    buton1.innerText="Confirmati rezervarea!";
    buton2.innerText="Rezervare Noua!";

    input3.appendChild(opt3);
    input3.appendChild(opt4);
    

    li3.appendChild(input3);
    li2.appendChild(input2);

    ul.appendChild(li3);
    ul.appendChild(li2);

    div1.appendChild(text);
    div2.appendChild(ul);
    div3.appendChild(buton1);
    div3.appendChild(buton2);

    div.appendChild(div1);
    div.appendChild(div2);
    div.appendChild(div3);

    buton1.addEventListener("click", function(){
        let div4=document.createElement("div");
        let text1=document.createElement("p");
        text1.innerText="Rezervarea pentru "+input2.value+" persoane in Austria in "+input3.value+" a fost confirmata!";
        div4.appendChild(text1);
        div.appendChild(div4);
        ok=true;

        var numar=input2.value;
        var data=input3.value;
        var serie="Martie";
        var cod=4;
        var rezervareTip1 = {
            numarPersoane : numar,
            dataRezervata : serie,
            tip : data,
            cod:cod
        };

        fetch('http://localhost:3000/tip1', {
            method: 'post', 
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(rezervareTip1)
        }).then(function(response) {
        console.log(response);
        })
        id+=1;
    })

    buton2.addEventListener("click", function(){
        li2.removeChild(input2);
        ul.removeChild(li2);
        div1.removeChild(text);
        div2.removeChild(ul);
        div3.removeChild(buton1);
        div3.removeChild(buton2);
        if (ok==true)
        {
            document.location.reload();
        }
    })
})

rezervare5.addEventListener("click",function(){
    

    let div=document.getElementById("mainContainer");
    let div1=document.getElementById("textBox");

    fetch('http://localhost:3000/tip1', {
        method: 'get' 
        }).then(function(response) {
            response.json().then((data) => {
    
                for(let i = 0; i < data.length; i++){
                    let p = document.createElement("p");
                    if(data[i].cod == 1 || data[i].cod == 2)
                    {
                        p.innerText="Ora de monitorie rezervata in " +data[i].tip+" pentru "+data[i].numarPersoane+" persoane, in data de "+data[i].dataRezervata+".";
                    }
                    else if(data[i].cod == 3)
                    {
                        p.innerText="Loc rezervat in tabara de iarna, in "+data[i].tip+" in perioada de "+data[i].dataRezervata+" pentru "+data[i].numarPersoane+" persoane.";
                    }
                    else
                    {
                        p.innerText="Loc rezervat in tabara din Austria din luna Martie, pentru "+data[i].numarPersoane+" persoane, in "+data[i].tip+".";
                    }
                    div1.appendChild(p);
                    id=data[i].id;
                }
                let buton=document.createElement("button");
                buton.innerText="Ascunde rezervarile!";
                div1.appendChild(buton);
                div.appendChild(div1);

                buton.addEventListener("click", function(){
                    document.location.reload();
                })

            })
        })
})

rezervare6.addEventListener("click", function(){
    fetch('http://localhost:3000/tip1',{
        method:'get',
        headers:{
            'Content-Type': 'application/json'
        }
    }).then((response) => {response.json().then((rezervari) => {
        fetch('http://localhost:3000/tip1/', {
        method: 'delete',
        headers: {
            'Content-Type': 'application/json'
        }
    }).then(function(response) {
        window.location.reload();
    })
    })
    })
    
    
})

rezervare7.addEventListener("click", function(){

    fetch('http://localhost:3000/tip1', {
        method: 'get' 
        }).then(function(response) {
            response.json().then((data) => {
    
                if(data[data.length-1].cod == 1)
                {
                    let ok=false;
                    let div=document.getElementById("mainContainer");
                    let div1=document.getElementById("textBox");
                    let text = document.createElement("p");
                    text.innerText = "Ati ales sa modificati ultima rezervare! Alegeti datele!";
                    let div2=document.getElementById("inputsContainer");
                    let ul=document.createElement("ul");
                    let li1=document.createElement("li");
                    let li2=document.createElement("li");
                    li1.innerText="Alegeti Data";
                    li2.innerText="Alegeti Numarul de persoane"
                    let input1=document.createElement("input");
                    input1.type="date";
                    let input2=document.createElement("input");
                    input2.type="number";
                    let div3=document.getElementById("confirmationContainer");
                    let buton1=document.createElement("button");
                    let buton2=document.createElement("button");
                    buton1.innerText="Confirmati rezervarea!";
                    buton2.innerText="Rezervare noua";
                
                    li1.appendChild(input1);
                    li2.appendChild(input2);
                
                    ul.appendChild(li1);
                    ul.appendChild(li2);
                
                    div1.appendChild(text);
                    div2.appendChild(ul);
                    div3.appendChild(buton1);
                    div3.appendChild(buton2);
                
                    div.appendChild(div1);
                    div.appendChild(div2);
                    div.appendChild(div3);

                    buton1.addEventListener("click", function(){
                        let div4=document.createElement("div");
                        let text1=document.createElement("p");
                        text1.innerText="Rezervarea pentru "+input2.value+" persoane in data de "+input1.value+" a fost confirmata!"
                        div4.appendChild(text1);
                        div.appendChild(div4);
                        ok=true;
                
                
                        var numar=input2.value;
                        var data=input1.value;
                        var cod=1;
                        var rezervareTip1 = {
                            numarPersoane : numar,
                            dataRezervata : data,
                            tip : "sezon",
                            cod : cod
                        };
                
                        fetch('http://localhost:3000/tip1',{
                         method:'get',
                        headers:{
                          'Content-Type': 'application/json'
                        }
                        }).then((response) => {response.json().then((rezervari) => {
                          fetch('http://localhost:3000/tip1/' , { 
                        method: 'put', 
                         headers: {
                         'Content-Type': 'application/json' 
                      },
                      body: JSON.stringify(rezervareTip1) 
                      }).then(function(response) {
                  })
                 })
                })
                        
                    })
                
                    buton2.addEventListener("click", function(){
                        li1.removeChild(input1);
                        li2.removeChild(input2);
                        ul.removeChild(li1);
                        ul.removeChild(li2);
                        div1.removeChild(text);
                        div2.removeChild(ul);
                        div3.removeChild(buton1);
                        div3.removeChild(buton2);
                        if (ok==true)
                        {
                            document.location.reload();
                        }
                    })
                }
                else if(data[data.length-1].cod == 2)
                {
                    let ok=false;
                    let div=document.getElementById("mainContainer");
                    let div1=document.getElementById("textBox");
                    let text = document.createElement("p");
                    text.innerText = "Ati ales sa modificati o rezervare! Alegeti datele!";
                    let div2=document.getElementById("inputsContainer");
                    let ul=document.createElement("ul");
                    let li1=document.createElement("li");
                    let li2=document.createElement("li");
                    li1.innerText="Alegeti Data";
                    li2.innerText="Alegeti Numarul de persoane"
                    let input1=document.createElement("input");
                    input1.type="date";
                    let input2=document.createElement("input");
                    input2.type="number";
                    let div3=document.getElementById("confirmationContainer");
                    let buton1=document.createElement("button");
                    let buton2=document.createElement("button");
                    buton1.innerText="Confirmati rezervarea!";
                    buton2.innerText="Rezervare noua!";

                    li1.appendChild(input1);
                    li2.appendChild(input2);

                    ul.appendChild(li1);
                    ul.appendChild(li2);

                    div1.appendChild(text);
                    div2.appendChild(ul);
                    div3.appendChild(buton1);
                    div3.appendChild(buton2);

                    div.appendChild(div1);
                    div.appendChild(div2);
                    div.appendChild(div3);

                    buton1.addEventListener("click", function(){
                        let div4=document.createElement("div");
                        let text1=document.createElement("p");
                        text1.innerText="Rezervarea pentru "+input2.value+" persoane in data de "+input1.value+" a fost confirmata!"
                        div4.appendChild(text1);
                        div.appendChild(div4);
                        ok=true;

                        var numar=input2.value;
                        var data=input1.value;
                        var cod=2;
                        var rezervareTip1 = {
                            numarPersoane : numar,
                            dataRezervata : data,
                            tip : "extra-sezon",
                            cod:cod
                        };

                        fetch('http://localhost:3000/tip1',{
                            method:'get',
                            headers:{
                                'Content-Type': 'application/json'
                            }
                        }).then((response) => {response.json().then((rezervari) => {
                            fetch('http://localhost:3000/tip1/' , { 
                            method: 'put', 
                            headers: {
                                'Content-Type': 'application/json' 
                            },
                            body: JSON.stringify(rezervareTip1) 
                            }).then(function(response) {
                        })
                        })
                        })
                    })

                    buton2.addEventListener("click", function(){
                        li1.removeChild(input1);
                        li2.removeChild(input2);
                        ul.removeChild(li1);
                        ul.removeChild(li2);
                        div1.removeChild(text);
                        div2.removeChild(ul);
                        div3.removeChild(buton1);
                        div3.removeChild(buton2);
                        if (ok==true)
                        {
                            document.location.reload();
                        }
    })
                }
                else if(data[data.length-1].cod == 3)
                {
                    let div=document.getElementById("mainContainer");
                    let div1=document.getElementById("textBox");
                    let text = document.createElement("p");
                    text.innerText = "Ati ales sa modificati o rezervare! Alegeti datele!";
                    let div2=document.getElementById("inputsContainer");
                    let ul=document.createElement("ul");
                    let li1=document.createElement("li");
                    let li2=document.createElement("li");
                    let li3=document.createElement("li");
                    li1.innerText="Alegeti Perioada";
                    li3.innerText="Alegeti Seria";
                    li2.innerText="Alegeti Numarul de persoane";
                    let input1=document.createElement("select");
                    let opt1=document.createElement("option");
                    let opt2=document.createElement("option");
                    opt1.innerText="Sezon";
                    opt2.innerText="Extra-Sezon";
                    let input3=document.createElement("select");
                    let opt3=document.createElement("option");
                    let opt4=document.createElement("option");
                    let opt5=document.createElement("option");
                    let opt6=document.createElement("option");
                    let opt7=document.createElement("option");
                    let opt8=document.createElement("option");
                    opt3.innerText="Seria 1";
                    opt4.innerText="Seria 2";
                    opt5.innerText="Seria 3";
                    opt6.innerText="Seria 4";
                    opt7.innerText="Seria 5";
                    opt8.innerText="Seria 6";
                    let input2=document.createElement("input");
                    input2.type="number";
                    let div3=document.getElementById("confirmationContainer");
                    let buton1=document.createElement("button");
                    let buton2=document.createElement("button");
                    buton1.innerText="Confirmati rezervarea!";
                    buton2.innerText="Rezervare Noua!";

                    input1.appendChild(opt1);
                    input1.appendChild(opt2);

                    input3.appendChild(opt3);
                    input3.appendChild(opt4);
                    input3.appendChild(opt5);
                    input3.appendChild(opt6);
                    input3.appendChild(opt7);
                    input3.appendChild(opt8);

                    li1.appendChild(input1);
                    li3.appendChild(input3);
                    li2.appendChild(input2);

                    ul.appendChild(li1);
                    ul.appendChild(li3);
                    ul.appendChild(li2);

                    div1.appendChild(text);
                    div2.appendChild(ul);
                    div3.appendChild(buton1);
                    div3.appendChild(buton2);

                    div.appendChild(div1);
                    div.appendChild(div2);
                    div.appendChild(div3);

                    buton1.addEventListener("click", function(){
                        let div4=document.createElement("div");
                        let text1=document.createElement("p");
                        text1.innerText="Rezervarea pentru "+input2.value+" persoane in perioada de "+input1.value+" in "+input3.value+" a fost confirmata!";
                        div4.appendChild(text1);
                        div.appendChild(div4);
                        ok=true;

                        var numar=input2.value;
                        var data=input3.value;
                        var serie=input1.value;
                        var cod=3;
                        var rezervareTip1 = {
                            numarPersoane : numar,
                            dataRezervata : serie,
                            tip : data,
                            cod:cod
                        };

                        fetch('http://localhost:3000/tip1',{
                        method:'get',
                        headers:{
                           'Content-Type': 'application/json'
                        }
                       }).then((response) => {response.json().then((rezervari) => {
                       fetch('http://localhost:3000/tip1/', { 
                          method: 'put', 
                        headers: {
                        'Content-Type': 'application/json' 
                         },
                        body: JSON.stringify(rezervareTip1) 
                         }).then(function(response) {
                        })
                     })
                 })
                    })

                    buton2.addEventListener("click", function(){
                        li1.removeChild(input1);
                        li2.removeChild(input2);
                        ul.removeChild(li1);
                        ul.removeChild(li2);
                        div1.removeChild(text);
                        div2.removeChild(ul);
                        div3.removeChild(buton1);
                        div3.removeChild(buton2);
                        if (ok==true)
                        {
                            document.location.reload();
                        }
                    })
                }
                else
                {
                    let div=document.getElementById("mainContainer");
                    let div1=document.getElementById("textBox");
                    let text = document.createElement("p");
                    text.innerText = "Ati ales sa modificati o rezervare! Alegeti datele!";
                    let div2=document.getElementById("inputsContainer");
                    let ul=document.createElement("ul");
                    
                    let li2=document.createElement("li");
                    let li3=document.createElement("li");
                    
                    li3.innerText="Alegeti Seria";
                    li2.innerText="Alegeti Numarul de persoane";
                    
                    
                    let input3=document.createElement("select");
                    let opt3=document.createElement("option");
                    let opt4=document.createElement("option");
                    
                    opt3.innerText="Seria 1";
                    opt4.innerText="Seria 2";
                    
                    let input2=document.createElement("input");
                    input2.type="number";
                    let div3=document.getElementById("confirmationContainer");
                    let buton1=document.createElement("button");
                    let buton2=document.createElement("button");
                    buton1.innerText="Confirmati rezervarea!";
                    buton2.innerText="Rezervare Noua!";
                
                    input3.appendChild(opt3);
                    input3.appendChild(opt4);
                    
                
                    li3.appendChild(input3);
                    li2.appendChild(input2);
                
                    ul.appendChild(li3);
                    ul.appendChild(li2);
                
                    div1.appendChild(text);
                    div2.appendChild(ul);
                    div3.appendChild(buton1);
                    div3.appendChild(buton2);
                
                    div.appendChild(div1);
                    div.appendChild(div2);
                    div.appendChild(div3);
                
                    buton1.addEventListener("click", function(){
                        let div4=document.createElement("div");
                        let text1=document.createElement("p");
                        text1.innerText="Rezervarea pentru "+input2.value+" persoane in Austria in "+input3.value+" a fost confirmata!";
                        div4.appendChild(text1);
                        div.appendChild(div4);
                        ok=true;
                
                        var numar=input2.value;
                        var data=input3.value;
                        var serie="Martie";
                        var cod=4;
                        var rezervareTip1 = {
                            numarPersoane : numar,
                            dataRezervata : serie,
                            tip : data,
                            cod:cod
                        };
                
                        fetch('http://localhost:3000/tip1',{
                            method:'get',
                            headers:{
                                'Content-Type': 'application/json'
                            }
                        }).then((response) => {response.json().then((rezervari) => {
                            fetch('http://localhost:3000/tip1/', { 
                            method: 'put', 
                            headers: {
                                'Content-Type': 'application/json' 
                            },
                            body: JSON.stringify(rezervareTip1) 
                            }).then(function(response) {
                        })
                        })
                        })                       
                    })
                
                    buton2.addEventListener("click", function(){
                        li2.removeChild(input2);
                        ul.removeChild(li2);
                        div1.removeChild(text);
                        div2.removeChild(ul);
                        div3.removeChild(buton1);
                        div3.removeChild(buton2);
                        if (ok==true)
                        {
                            document.location.reload();
                        }
                    })
                }

            })
        })
})