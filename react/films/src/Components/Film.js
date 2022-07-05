import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import '../styles/Film.css';
import Button from './Buttonn';
import list from './FilmsList'
import {Link} from 'react-router-dom'
const Film = ({elem,onClick}) => {
    const listItems = elem.map((e,index) =>
        <li key = {e.id}>
            
            <h1>{e.title}</h1>
            <img src={e.img}/>
            <p>{e.description.substring(0,5).concat('...')}</p>
            <Button value = "Delete" onClick={
                ()=>{
                onClick(e.id)
            }} />
            <Link className='more' key={e.id} to={`/film/${e.id}`}>more...</Link>
            {/* <Button value = "Go To"  /> */}
        </li>
    );
    return( 
        <div  className="film-container">
            <ul  className="list-group">{listItems}</ul>


        </div>
    )
}



export default Film;