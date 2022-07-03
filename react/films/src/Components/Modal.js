import React, { useRef, useState } from "react";
import ReactDOM from "react-dom";
// import AppFC from "../App";
import '../styles/Modal.css'
import { list } from "./Film";
const Modal =({onClose,show,addElem}) => {
    const addedName = useRef("")
    const addedDesc = useRef("");
    // const [ post,setPost] = useState('')
    if(!show){
        return null
    }
    
    const addElement = (e) => {
        e.preventDefault();
        const newFilm = {
            id:7,
            title:{addedName},
            img:'',
            description:{addedDesc}     
        }  
        addElem(newFilm)
    }
    return (
        <div className="modal" onClick={onClose}>
            <div className="modal-content" onClick={e => e.stopPropagation()}>
                <h4>Add Film</h4>
                {/* <p>{addedName}</p> */}
                <button className="close" onClick={onClose}>X</button>
                <input ref={addedName} placeholder="Name"/>
                <input ref={addedDesc} placeholder="Description"/>
                <button className="add-film" onClick={
                    addElement
                }>Add Film</button>
            </div>
        </div>
    )
}
export default Modal;