--1
select s.s_id as "ID", s.s_last as "Student/curs", 'student' as "Tip"
from student s, faculty f
where s.f_id = f.f_id
and f.f_last = 'Brown'
union
select c.course_no as "ID", c.course_name as "Student/curs", 'curs' as "Tip"
from course_section cs, course c, faculty f
where cs.course_no = c.course_no
and cs.f_id = f.f_id 
and f.f_last = 'Brown';

--2
select s.s_id, s.s_last
from student s, enrollment e, course_section cs
where s.s_id = e.s_id
and e.c_sec_id = cs.c_sec_id
and (select c.course_name
     from course c
     where cs.course_no = c.course_no) = 'Database Management'
and (select c.course_name
     from course c
     where cs.course_no = c.course_no) != 'Programing in C++';


--3
select distinct s.s_id, s.s_last
from student s, enrollment e
where s.s_id=e.s_id
and (e.grade = 'C' or e.grade is null);


--4
select l.loc_id, l.bldg_code, l.capacity
from location l
where l.capacity = (select max(capacity)
                    from location);
                    
                    
--5
CREATE TABLE t (id NUMBER PRIMARY KEY);
INSERT INTO t VALUES(1);
INSERT INTO t VALUES(2);
INSERT INTO t VALUES(4);
INSERT INTO t VALUES(6);
INSERT INTO t VALUES(8);
INSERT INTO t VALUES(9);
--o sa presupun ca disponibil=nu se afla in tabel si este disponibil sa fie eventual introdus
select min(id)+1 as "Minim(primul)/Maxim(al doilea)"
from t
where id+1 not in (select id from t)
union
select max(id)-1 as "Maxim"
from t
where id-1 not in (select id from t);


--6
select f.f_id as "cod profesor" , f.f_last as "nume profesor",
(select decode(count(s.s_id), 0, 'Nu', 'Da ('||count(s.s_id)||')' )
from student s
where s.f_id = f.f_id) as "Student",
(select decode(count(cs.c_sec_id), 0, 'Nu', 'Da ('||count(cs.c_sec_id)||')' )
from course_section cs
where cs.f_id = f.f_id) as "Curs"
from faculty f;


--7
select t1.term_desc, t2.term_desc
from term t1, term t2
where substr(t1.term_desc, length(t1.term_desc), 1) != substr(t2.term_desc, length(t2.term_desc), 1)
and substr(t1.term_desc, 1, length(t1.term_desc)-1) = substr(t2.term_desc, 1, length(t2.term_desc)-1);


--8


--9
select distinct cs1.course_no, cs2.course_no
from course_section cs1, course_section cs2
where cs1.term_id = cs2.term_id
and cs1.course_no != cs2.course_no;


--10
select c.course_no, c.course_name, t.term_desc, cs.max_enrl
from course c, term t, course_section cs
where c.course_no=cs.course_no
and cs.term_id= t.term_id
and cs.max_enrl < (select min(cs2.max_enrl)
                    from course_section cs2, location l2
                    where cs2.loc_id = l2.loc_id and l2.loc_id=1);
                    
                    
--11
select distinct c.course_name, cs.max_enrl
from course c, course_section cs
where cs.max_enrl = (select min(max_enrl)
                    from course_section)
and c.course_no = cs.course_no;


--12
select f.f_last, (select avg(cs.max_enrl)
                    from course_section cs
                    where cs.f_id = f.f_id) as "medie"
from faculty f;


--13
select f.f_last, (select count(s.s_id)
                  from student s
                  where s.f_id = f.f_id) as "numar elevi"
from faculty f
where  (select count(s.s_id)
        from student s
        where s.f_id = f.f_id)>= 3;
        

--14
select distinct c.course_name, (select max(capacity)
                        from location
                        where loc_id=cs.loc_id), cs.loc_id
from course c, course_section cs
where c.course_no = cs.course_no;


--15
select (select avg(cs.max_enrl)
        from course_section cs
        where cs.term_id = t.term_id)
from term t
where t.term_desc like '%2007%';