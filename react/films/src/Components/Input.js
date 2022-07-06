import React from 'react';

function Input({className,placeholder,onChange}) {
    return (
        <input className={className} placeholder={placeholder} onChange={onChange}/>
    )
}

export default Input;