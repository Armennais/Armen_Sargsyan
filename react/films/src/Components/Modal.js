import React, { useRef, useState } from "react";
import ReactDOM from "react-dom";
import '../styles/Modal.css'
import list  from "./FilmsList";
import img6 from '../cin.jpg'
const Modal =({onClose,show,addElem,elem}) => {
    const[title,setTitle] = useState('')
    const[desc,setDesc] = useState('')

    if(!show){
        return null
    }
    
    const addElement = () => {
        console.log(elem.length,"====elem LEnght")

        const newFilm = {
            id:elem.length,
            title:title,
            img:img6,
            description:desc
        }  

        addElem(newFilm)
    }
    return (
        <div className="modal" onClick={onClose}>
            <div className="modal-content" onClick={e => e.stopPropagation()}>
                <h4>Add Film</h4>
                <button className="close" onClick={onClose}>X</button>
                <input placeholder="Name" onChange={(e)=>setTitle(e.target.value)}/>
                <input placeholder="Description" onChange={(e)=>setDesc(e.target.value)}/>
                <button className="add-film" onClick={
                    addElement
                }>Add Film</button>
            </div>
        </div>
    )
}
export default Modal;