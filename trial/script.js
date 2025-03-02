// alert('boom')
// document mozilla mdn
// document.url document.title document.scrpits
const myElement=document.querySelectorAll('.thisClass')
// can use getElementById or getElementByClass
console.log(myElement)

const myPElements=document.querySelector('p')
myPElements.textContent='I am being changed'

const myElements=document.querySelectorAll('p')
myElements.forEach(p => {
    p.textContent='We all are changed using js'
});

const myNewPara=document.createElement('p')
myNewPara.textContent='I was added via js'
document.querySelector('body').appendChild(myNewPara)

document.querySelector('button').addEventListener('click',(event)=>{
    event.target.textContent='clicked'
})

function myValidation(){
    let myValue=document.getElementById('myForm').value
    if(isNaN(value)){
        console.log('not a valid input')
    }else{
        console.log('valid input')
    }
}
// event.preventDefault()
// createTextNode appendChild