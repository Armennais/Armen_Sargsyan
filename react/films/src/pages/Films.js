import React, { useEffect, useState,useContext} from 'react';
import Film from '../Components/Film';
import '../styles/App.css';
import {FilmContext} from '../Components/Context'
import Input from '../Components/Input';
import Button from '../Components/Buttonn';
import Modal from '../Components/Modal';
let filtredList = []


const Films = () =>{
  const[searchText,setSearchText] = useState('')
  const [filmElements, setFilmElements] = useState([]);
  const searchFilm = (e) => {
    setSearchText(e.target.value)
  }
  const {allFilms,setAllFilms} = useContext(FilmContext)
  
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
    console.log(index)
    setAllFilms((allFilms) => allFilms.filter((i) => i.id !== index)
    );
}

filtredList = filmElements
  const[show,setShow] = useState(false);
  return(

    <div className="AppFC">
      <p id="count">Count: {filmElements.length}</p>
      <Input className="search" placeholder = "Search" onChange = {searchFilm}/>
      <Button value= "ADD"  onClick={() => setShow(true)} />
      <Modal onClose={()=> setShow(false)}  show={show} addElem ={AddElem} elem = {allFilms}/>
      <Film  elem = {filmElements} onClick ={deleteItem} /> 
     </div>
     
  )
}
export {filtredList}
export default Films;
