import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import '../styles/Film.css';
import Button from './Buttonn';

import img from '../img.jpg'
import img2 from '../img2.jpg'
import img3 from '../img3.jpg'
import img4 from '../img4.jpg'
import img5 from '../img5.jpg'
import img6 from '../img6.jpg'

export const list = [{
    id:0,
    title: 'Polis',
    img: img,
    description: 'description1'
},{
    id:1,
    title: 'Horns',
    img: img2,
    description: 'description2'
},{
    id:2,
    title: 'Black Panther',
    img: img3,
    description: 'description3'
},{
    id:3,
    title: 'Gods of Egypt',
    img: img4,
    description: 'description4'
},{
    id:4,
    title: 'Freedom',
    img: img5,
    description: 'description5'
},{
    id:5,
    title: 'Merrick',
    img: img6,
    description: 'description6'
}];



const Film = ({setElem,elem}) => {

    const deleteItem = (index) =>{
        setElem((elem) => elem.filter((i) => i.id !== index));
    }
  

    const listItems = elem.map((e,index) =>
        <li key = {e.id}>
            
            <h1>{e.title}</h1>
            <img src={e.img}/>
            <p>{e.description}</p>
            <Button value = "Delete" onClick={
                ()=>{
                deleteItem(e.id)
            }} />
            
        </li>
    );
    return( 
        <div  className="film-container">
            <ul  className="list-group">{listItems}</ul>


        </div>
    )
}



export default Film;