import React, { useRef, useState } from "react";
import ReactDOM from "react-dom";
// import AppFC from "../App";
import '../styles/Modal.css'
import { list } from "./Film";
const Modal =({onClose,show,addElem}) => {
    const[title,setTitle] = useState('')
    const[desc,setDesc] = useState('')

    if(!show){
        return null
    }
    
    const addElement = (e) => {
        e.preventDefault();
        const newFilm = {
            id:7,
            title:{title},
            img:'',
            description:{desc}   ,
            // a:alertAAA")  
        }  
        // console.log(newFilm)
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