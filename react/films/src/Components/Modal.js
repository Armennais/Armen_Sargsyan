import React, { useRef } from "react";
import ReactDOM from "react-dom";
// import AppFC from "../App";
import '../styles/Modal.css'
import { list } from "./Film";
const Modal =({onClose,show,elem,setElem}) => {
    const addedName = useRef("")
    const addedDesc = useRef("");

    if(!show){
        return null
    }
    
    const addElement = () => {
        // e.preventDefault();
        const newFilm = {
            id:7,
            title:{addedName},
            img:'',
            description:{addedDesc}     
        }  
        // setElem([...elem,newFilm])
        console.log(newFilm.title)
    }
    return (
        <div className="modal" onClick={onClose}>
            <div className="modal-content" onClick={e => e.stopPropagation()}>
                <h4>Add Film</h4>
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