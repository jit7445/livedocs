'use client'
import React from 'react'
import { Button } from './ui/button';
import Image from 'next/image';
import { useRouter } from 'next/navigation';
import { createDocument } from '@/lib/actions/room.actions';

type AddDocumentBtnProps = {
  userId: string;
  email: string;
};

const AddDocumentBtn = ({ userId, email }: AddDocumentBtnProps) => {
  const router = useRouter();

  const AddDocumentHandler = async () => {
    try {
      const room = await createDocument({ userId, email });
      if (room) router.push(`/document/${room.id}`);
    } catch (err) {
      console.log("err:", err);
    }
  };

  return (
    <Button type='submit' onClick={AddDocumentHandler} className='gradient-blue flex gap-1 shadow-md'>
      <Image
        src="/assets/icons/add.svg"
        alt="add"
        width={24}
        height={24}
      />
      <p className='hidden sm:block'>
        Start Document
      </p>
    </Button>
  );
};

export default AddDocumentBtn;
