import React, { useEffect, useState } from 'react';
import ReactDOM from 'react-dom/client';
import Film from './Components/Film';
import list from './Components/FilmsList'
import './styles/App.css';
import Button from './Components/Buttonn';
import Modal from './Components/Modal';
let filtredList = []
export const AppFC = () =>{
  const[searchText,setSearchText] = useState('')
  const [elem,setElem] = useState(list);
  const [filmElements, setFilmElements] = useState([]);
  const searchFilm = (e) => {
    setSearchText(e.target.value)
  }
  
  
  useEffect(() =>{
    setFilmElements(!searchText ? elem : elem.filter((e) => e.title.toLowerCase().includes(searchText.toLowerCase())));
  },[searchText])

  useEffect(()=> {
    setFilmElements(elem)
  },[elem])
  
  const AddElem = (newPost) =>{
    setShow(false)

    setElem([...elem,newPost])
  }
  const deleteItem = (index) =>{
    setElem((elem) => elem.filter((i) => i.id !== index));
    console.log(elem)
    console.log(index,"===Index")
    for (let i = index; i < elem.length; i++) {
    console.log(i,"===ID")

      elem[i].id = elem[i].id - 1;
    }
}


  const[show,setShow] = useState(false);
  filtredList = filmElements
  return(

    <div className="AppFC">
      <p id="count">Count: {filmElements.length}</p>
      <input type="text" className="input" placeholder="Search" onChange={searchFilm}/>
      <Button value= "ADD"  onClick={() => setShow(true)} />
      <Modal onClose={()=> setShow(false)}  show={show} addElem ={AddElem} elem = {elem}/>
      <Film  elem = {filmElements} onClick ={deleteItem} /> 
     </div>
  )
}
export {filtredList}
export default AppFC;
