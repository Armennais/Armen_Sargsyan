import React, { useRef, useState } from "react";
import "../styles/Modal.css";
import img6 from "../images/cin.jpg";
import Input from "./Input";

const Modal = ({ onClose, show, addElem, elem }) => {
  const [title, setTitle] = useState("");
  const [desc, setDesc] = useState("");

  if (!show) {
    return null;
  }

  const addElement = () => {
    console.log(elem.length, "====elem LEnght");

    const newFilm = {
      id: Date.now(),
      title: title,
      img: img6,
      description: desc,
    };

    addElem(newFilm);
  };
  return (
    <div className="modal" onClick={onClose}>
      <div className="modal-content" onClick={(e) => e.stopPropagation()}>
        <h4>Add Film</h4>
        <button className="close" onClick={onClose}>
          X
        </button>
        <Input placeholder="Name" onChange={(e) => setTitle(e.target.value)} />
        <Input
          placeholder="Description"
          onChange={(e) => setDesc(e.target.value)}
        />
        <button className="add-film" onClick={addElement}>
          Add Film
        </button>
      </div>
    </div>
  );
};
export default Modal;
