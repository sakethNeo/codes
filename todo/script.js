var ul=document.getElementById('list')
var li;

var addButton=document.getElementById('add')
addButton.addEventListener('click',addItem)

var removeButton=document.getElementById('remove')
removeButton.addEventListener('click',removeItem)

function addItem(){
    var input=document.getElementById('input')
    var item=input.value
    var textNode=document.createTextNode(item)

    //create li
    li=document.createElement('li')

    //create checkbox
    var checkbox=document.createElement('input')
    checkbox.type='checkbox'
    checkbox.setAttribute('class','check')

    //create lebel
    var label=document.createElement('label')

    //add these elements
    ul.appendChild(label)
    li.appendChild(checkbox)
    li.appendChild(textNode)
    li.appendChild(label)
    ul.insertBefore(li,ul.childNodes[0])

    //clear input
    input.value=''

}

function removeItem(){
    li=ul.children
    for (let index = 0; index < li.length; index++) {
        while(li[index] && li.children[0].checked){
            ul.removeChild(li[index])
        }
    }
}
