import React, { useEffect, useState } from 'react';
import ReactDOM from 'react-dom/client';
import Film from './Components/Film';
import list from './Components/FilmsList'
import './styles/App.css';
import Button from './Components/Buttonn';
import Modal from './Components/Modal';
let filtredList = []

const AppFC = () =>{
  const[searchText,setSearchText] = useState('')
  const [allFilms,setAllFilms] = useState(list);
  const [filmElements, setFilmElements] = useState([]);
  const searchFilm = (e) => {
    setSearchText(e.target.value)
  }
  
  
  useEffect(() =>{
    setFilmElements(!searchText ? allFilms : allFilms.filter((e) => e.title.toLowerCase().includes(searchText.toLowerCase())));
  },[searchText])

  useEffect(()=> {
    setFilmElements(allFilms)
  },[allFilms])
  
  const AddElem = (newPost) =>{
    setShow(false)

    setAllFilms([...allFilms,newPost])
  }
  const deleteItem = (index) =>{
    setAllFilms((allFilms) => allFilms.filter((i) => i.id !== index));
}


  const[show,setShow] = useState(false);
  filtredList = filmElements
  return(

    <div className="AppFC">
      <p id="count">Count: {filmElements.length}</p>
      <input type="text" className="input" placeholder="Search" onChange={searchFilm}/>
      <Button value= "ADD"  onClick={() => setShow(true)} />
      <Modal onClose={()=> setShow(false)}  show={show} addElem ={AddElem} elem = {allFilms}/>
      <Film  elem = {filmElements} onClick ={deleteItem} /> 
     </div>
  )
}
export {filtredList}
export default AppFC;
