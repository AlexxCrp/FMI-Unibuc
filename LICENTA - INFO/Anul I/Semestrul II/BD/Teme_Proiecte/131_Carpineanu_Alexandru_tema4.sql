--1
select distinct s.s_last as "nume"
from student s, enrollment e
where s.s_id not in (select e.s_id
        from enrollment e
        where e.grade is null); 


--2
select l.bldg_code
from location l
where l.bldg_code not in (select l1.bldg_code
                        from location l1
                        where l1.loc_id not in (select cs.loc_id
                                                from course_section cs));


--3
select f.f_last as "nume", f.f_id as "cod"
from faculty f
where f.f_id in (select s.f_id
                from student s
                where s.s_id in (select e.s_id
                                from enrollment e
                                where e.grade = 'A'))
and
f.f_id in (select cs.f_id
            from course_section cs
            where cs.course_no in (select c.course_no
                                from course c
                                where c.course_name = 'Database Management'));


--4
select f.f_last
from faculty f
where f.f_id in (select cs.f_id
                from course_section cs
                where cs.max_enrl in (select max(max_enrl)
                                        from course_section))
or
f.f_id in (select cs.f_id
            from course_section cs
            where cs.loc_id in (select l.loc_id
                                from location l
                                where l.capacity in (select max(capacity)
                                                    from location)));
                                                        

--5

select f.f_id
from faculty f
where f.loc_id = (select l.loc_id
                    from location l
                    where capacity = (select min(capacity)
                                        from location))
and
f.f_id = (select cs.f_id 
            from course_section cs
            where cs.max_enrl = (select min(max_enrl)
                                from course_section)
            and
            cs.c_sec_id in (select cs.c_sec_id
                            from course_section cs
                            where cs.loc_id = (select l.loc_id
                                             from location l
                                             where l.capacity = (select max(capacity)
                                                                 from location))));


--6
with valoare1 as (select distinct l.capacity
                    from location l
                    where l.loc_id in(select cs.loc_id
                                    from course_section cs
                                    where f_id = (select f_id
                                                    from faculty
                                                    where f_last = 'Marx'
                                                    and f_first = 'Teresa'))),
valoare2 as (select cs.max_enrl
            from course_section cs, enrollment e
            where cs.c_sec_id=e.c_sec_id
            and e.s_id = (select s.s_id
                                from student s
                                where s.s_last='Jones'))
select avg(capacity), avg(max_enrl)
from valoare1, valoare2;


--7
with locuri as (select l.loc_id
                from location l, course_section cs, course c
                where l.loc_id = cs.loc_id
                and cs.course_no = c.course_no
                and c.course_name like '%Systems%')
select l.bldg_code, avg(l.capacity)
from location l
where l.loc_id in (select * from locuri)
group by l.bldg_code;


--9
select
case when not exists (select course_name
                    from course
                    where  course_name in (select course_name
                                             from course
                                             where lower(course_name) like '%java%'))
                    then course_name
else (select course_name from course)
end
from course c;


--11
select distinct t.term_desc 
from term t,course_section cs,course c
where t.term_id = cs.term_id
and cs.course_no = c.course_no
and cs.sec_num in (select max(cs.sec_num) 
                    from course_section cs,course c
                    where c.course_name like ('%Database%')) 
                    and cs.course_no = c.course_no;


--12
select e.grade
from enrollment e, student s
where s.s_id = e.s_id
group by e.grade
having count(distinct s.s_id) = (select max(count(distinct s1.s_id))
                               from student s1, enrollment e1
                               where s1.s_id=e1.s_id
                               group by e1.grade
                               having e1.grade is not null);
        

--13
select t.term_desc, count(c.course_name)
from term t, course c, course_section cs
where cs.term_id=t.term_id
and cs.course_no=c.course_no
and c.credits=3
group by t.term_desc
having count(c.course_name) = (select max(count(c1.course_name))
                                from course c1, course_section cs1, term t1
                                where cs1.course_no=c1.course_no
                                and cs1.term_id=t1.term_id 
                                and c1.credits=3
                                group by t1.term_desc);
                                
                                
--15
select bldg_code, count(room)
from location
group by bldg_code
having count(room) = 1;